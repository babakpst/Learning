
#include "stdafx.h"
#include "Calc_Cls.h"

Calc_Cls::Calc_Cls(int a, int b, double c, double d) {
	a_int = a;
	b_int = b;
	a_dbl = c;
	b_dbl = d;
};


Calc_Cls::Calc_Cls(int a, double b) {
	a_int = a;
	a_dbl = b;
}


void Calc_Cls::Calculation_fn() {
	res_int = a_int + b_int;
	res_dbl = a_dbl + b_dbl;
};


/*
Calc_Cls::~Calc_Cls() {
	delete a_int, b_int, a_dbl, b_dbl;
};
*/

/*
Calc_Cls::~Calc_Cls() {
	delete a_int, a_dbl;
};
*/