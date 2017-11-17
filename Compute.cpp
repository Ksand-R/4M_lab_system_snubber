#include <cmath>
#include "row_table.h"
#include "compute.h"


static double eps;
static double m, c, k;
static double u0, du0;

struct VectorRow {
	unsigned i;
	double hi_1;
	double xi;
	//std::vector<double> vi;
	std::vector<double> vi_cor;
	std::vector<double> vi_pr;
	std::vector<double> viPr_vi_сor;
	std::vector<double> s;
	std::vector<double> vi_utoch;
	std::vector<double> vi_itog;	
	int stepInc;
	int stepDec;

	operator Row () {
		Row tmp;
		tmp.i = i;
		tmp.hi_1 = hi_1;
		tmp.xi = xi;
		tmp.stepDec = stepDec;
		tmp.stepInc = stepInc;

		tmp.vi_pr = vi_pr[0];			
		tmp.vi_cor = vi_cor[0];
		tmp.viPr_vi_сor = viPr_vi_сor[0];
		tmp.s = sqrt(s[0] * s[0] + s[1] * s[1]);
		tmp.vi_itog = vi_itog[0];
		tmp.vi_utoch = vi_utoch[0];
		return tmp;
	}
};



std::vector<double> operator+(std::vector<double> v1, std::vector<double>v2) {
	std::vector<double> res(2);
	res[0] = v1[0] + v2[0];
	res[1] = v1[1] + v2[1];
	return res;
}
std::vector<double> operator*(double a, std::vector<double>v) {
	std::vector<double> res(2);
	res[0] = a * v[0];
	res[1] = a * v[1];
	return res;
}
std::vector<double> operator/(std::vector<double>v, double a) {
	std::vector<double> res(2);
	res[0] = v[0] / a;
	res[1] = v[1] / a;
	return res;
}




void set_task_param(double _m, double _c, double _k)
{
	m = _m;
	c = _c;
	k = _k;

}

std::vector<double> diff_eq(double x, std::vector<double> u)
{
	std::vector<double> f(2);
	f[0] = u[1];
	f[1] = -(k* u[0] + c * u[1]) / m;
	return f;
}

std::vector<double> RK_4(func f, double h, double x, std::vector<double> y)
{
	std::vector<double> k1 = f(x, y);
	std::vector<double> k2 = f(x + h / 2., y + (h / 2.) * k1);
	std::vector<double> k3 = f(x + h / 2., y + (h / 2.) * k2);
	std::vector<double> k4 = f(x + h, y + (h * k3));
	return y + (h / 6.) * (k1 + 2. * k2 + 2. * k3 + k4);


}

//std::vector<double> RK4(func f, double h, double x, std::vector<double> v) {
//	std::vector<double> k1 = f(x, v);
//	std::vector<double> k2 = f(x + h / 2, v + (h / 2)*k1);
//	std::vector<double> k3 = f(x + h / 2, v + (h / 2)*k2);
//	std::vector<double> k4 = f(x + h, v + h*k3);
//	return v + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
//}

void double_count(Method method, func f, int p,
 VectorRow* R)
	{
		R->stepDec = R->stepInc = 0;

		std::vector<double> v1 = method(f, R->hi_1, R->xi, R->vi_pr);
		std::vector<double> v2 = method(f, R->hi_1*0.5, 
			R->xi + R->hi_1*0.5, method(f, R->hi_1*0.5, R->xi, R->vi_pr));
		R->s = (v2 + (-1)*v1) / (pow(2, p) - 1);

		while (sqrt(R->s[0] * R->s[0] + R->s[1] * R->s[1]) > eps) {
			R->hi_1 *= 0.5;
			R->stepDec++;
			v1 = method(f, R->hi_1, R->xi, R->vi_pr);
			v2 = method(f, R->hi_1*0.5, R->xi + R->hi_1*0.5, method(f, R->hi_1*0.5, R->xi, R->vi_pr));
			R->s = (v2 + (-1)*v1) / (pow(2, p) - 1);
		}
		R->xi += R->hi_1;
		if (sqrt(R->s[0] * R->s[0] + R->s[1] * R->s[1]) < eps / pow(2, p + 1)) {
			R->stepInc++;
		}
		R->vi_itog = R->vi_pr = v1;
		R->vi_cor = v2;
		R->viPr_vi_сor = v1 + (-1)*v2;
		R->vi_utoch = v1 + pow(2, p)*R->s;
}

void Integrate(Method method, func f, double x0, 
	double maxX, double y0, 
	double dy0, int maxI, double h0,
	double eps_,  Table* T, 
	int p, double _m, double _c, double _k)
{
	VectorRow R1;
	eps = eps_;
	set_task_param(_m, _c, _k);
	std::vector<double> tmp_y0(2);
	tmp_y0[0] = y0;
	tmp_y0[1] = dy0;
	int i = 0;
	VectorRow tmp;
	tmp.i = 0;
	tmp.hi_1 = h0;
	tmp.xi = x0;
	tmp.vi_pr = tmp_y0;
	tmp.vi_cor = tmp_y0;
	tmp.viPr_vi_сor = std::vector<double>(2, 0.0);
	tmp.s = std::vector<double>(2, 0.0);
	tmp.vi_utoch = tmp_y0;
	tmp.vi_itog = std::vector<double>(2, 0.0);
	tmp.stepInc = 0;
	tmp.stepDec = 0;
	//T->AddRow(tmp);
	for (i = 1; i < maxI; ++i) {
		tmp.i = i;
		R1 = tmp;
		double_count(RK_4, f, 4, &tmp);
		if (tmp.xi <= maxX) {
			T->AddRow(tmp);
			if (tmp.stepInc) tmp.hi_1 *= 2;
			if (tmp.xi > maxX - 0.000000001) break;
		}
		else {
			tmp = R1;
			tmp.hi_1 *= 0.5;
			tmp.stepDec++;
			i--;
			continue;
		}
	}
}

