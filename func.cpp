#include "kdv.h"

double func(double y_bb,double y_b,
		double y_0,
		double y_a,double y_aa,
		double deltaX)
{
	double a = -1.*(y_aa - (2.*y_a) + (2.*y_b)- y_bb)/(2.*deltaX*deltaX*deltaX);
	double b = (3.*y_0*(y_a-y_b))/(deltaX);
	return a-b;
}

