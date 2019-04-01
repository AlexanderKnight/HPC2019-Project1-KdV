#include "kdv.h"

double k1(double y_bb, double y_b, double y_0, 
		double y_a, double y_aa, double deltaX)
{
	return func(y_bb,y_b,y_0,y_a,y_aa,deltaX);
}

double k2(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double deltaX, double h)
{
	double y = y_0 + k1(y_bb,y_b,y_0,y_a,y_aa ,deltaX)*(h/2.);
	return func(y_bb,y_b,y,y_a,y_aa,deltaX);
}

double k3(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double deltaX, double h)
{
	double y = y_0 + k2(y_bb,y_b,y_0,y_a,y_aa,deltaX,h)*(h/2.);
	return func(y_bb,y_b,y,y_a,y_aa,deltaX);
}

double k4(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double deltaX, double h)
{
	double y = y_0 + k3(y_bb,y_b,y_0,y_a,y_aa,deltaX,h)*h;
	return func(y_bb,y_b,y,y_a,y_aa,deltaX);
}

double rk4(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double deltaX, double h)
{
	double m = (1./6.)*k1(y_bb,y_b,y_0,y_a,y_aa,deltaX)+
			(1./3.)*k2(y_bb,y_b,y_0,y_a,y_aa,deltaX,h)+
			(1./3.)*k3(y_bb,y_b,y_0,y_a,y_aa,deltaX,h)+
			(1./6.)*k4(y_bb,y_b,y_0,y_a,y_aa,deltaX,h);
	return (y_0 + m*h);
}

