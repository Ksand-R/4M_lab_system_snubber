#pragma once
#include  <vector>
#include "row_table.h"

typedef std::vector<double>(*func)(double, std::vector<double>);
typedef std::vector<double>(*Method) (func, double, double, 
	std::vector<double>);

std::vector<double> diff_eq(double x, std::vector<double> y);
std::vector<double> RK_4(func, double h, double x, std::vector<double> y);

//const Method method_array[] = { RK4 };

void Integrate(Method method, func func, double x0, double maxX,
	double y0, double dy0, int maxI, double h0, double eps_,
	 Table* T, int p, double m, double c, double k);