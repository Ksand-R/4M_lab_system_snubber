#pragma once
#include <list>
#include <fstream>

const int task = 1;

const int N = 100000;

struct Row {
	unsigned i;
	double hi_1; // hi - 1
	double xi;
	double vi_pr; // prev
	double vi_cor; // corrected
	double viPr_vi_ñor; // prev - cor
	double s;
	double vi_utoch;
	double vi_itog;
	double stepInc;
	double stepDec;
	
	friend std::ifstream& operator >> (std::ifstream & ins, Row& t) {
		ins >> t.i >> t.hi_1 >> t.xi >> t.vi_pr >>
			t.vi_cor >> t.viPr_vi_ñor >> t.s >> t.vi_utoch
			>> t.vi_itog >> t.stepDec >> t.stepInc;
		return ins;
	}
	friend std::ofstream& operator<< (std::ofstream & outs, Row& t) {
		outs << t.i << ' ' << t.hi_1 << ' '
			<< t.xi << ' ' << t.vi_pr << ' '
			<< t.vi_cor << ' ' << t.viPr_vi_ñor
			<< ' ' << t.s << ' ' << t.vi_utoch
			<< ' ' << t.vi_itog << ' ' << t.stepDec
			<< ' ' << t.stepInc << std::endl;
		return outs;
	}
};

class Table {
	std::list<Row> _Table;
public:
	Table() {}
	Table(const Table& t) :_Table(t._Table) {}
	~Table() {}

	typedef std::list<Row>::iterator iterator;

	iterator begin() { return _Table.begin(); }
	iterator end() { return _Table.end(); }

	int GetSize() { return _Table.size(); }
	void AddRow(Row _row) { _Table.push_back(_row); }
	Row GetLastRow() { return *(--_Table.end()); }

	void Clear() { _Table.clear(); }

	friend std::ifstream& operator >> (std::ifstream & is, Table& t) {
		Row _row;
		while (!is.eof()) {
			is >> _row;
			if (!is.eof()) t.AddRow(_row);
		}
		return is;
	}
	friend std::ofstream& operator<< (std::ofstream & os, Table& t) {
		for (auto it = t.begin(); it != t.end(); it++)
			os << (*it);
		return os;
	}
};
