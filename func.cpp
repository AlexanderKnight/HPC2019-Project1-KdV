#include "kdv.h"

/*
    Solved Korteweg-de Vries equation. Started with
    d_t u + d_x^3 u + 6u(d_x u)=0
    Broke up derivatives into discrete differences
    to caclulate numerically.

    To calculate point u_i, it needs points u_(i+/-1) 
    and u_(i+/-2). The convention is such that 
    y_bb --> y-back-back = y_(i-2)
    y_aa --> y-after-after = y_(i+2)
*/
double func(double y_bb, double y_b,
		double y_0,
		double y_a, double y_aa, double deltaX)
{
	double a = -1.*(y_bb - (2.*y_b) + (2.*y_a)- y_aa)/(2.*deltaX*deltaX*deltaX);
	double b = (6.*y_0*(y_a-y_b))/(2.*deltaX);
	return a+b;
}
