#include "kdv.h"

double k1(double y_bb, double y_b, double y_0, 
		double y_a, double y_aa, double t_0)
{
	return func(y_bb,y_b,y_0,y_a,y_aa,t_0);
}

double k2(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double t_0, double h)
{
	double y = y_0 + k1(y_bb,y_b,y_0,y_a,y_aa ,t_0)*(h/2.);
	double t = t_0 + (h/2.);
	return func(y_bb,y_b,y,y_a,y_aa,t);
}

double k3(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double t_0, double h)
{
	double y = y_0 + k2(y_bb,y_b,y_0,y_a,y_aa,t_0,h)*(h/2.);
	double t = t_0 + (h/2.);
	return func(y_bb,y_b,y,y_a,y_aa,t);
}

double k4(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double t_0, double h)
{
	double y = y_0 + k3(y_bb,y_b,y_0,y_a,y_aa,t_0,h)*h;
	double t = t_0 + h;
	return func(y_bb,y_b,y,y_a,y_aa,t);
}

double rk4(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double t_0, double h)
{
	double m = (1./6.)*k1(y_bb,y_b,y_0,y_a,y_aa,t_0)+
			(1./3.)*k2(y_bb,y_b,y_0,y_a,y_aa,t_0,h)+
			(1./3.)*k3(y_bb,y_b,y_0,y_a,y_aa,t_0,h)+
			(1./6.)*k4(y_bb,y_b,y_0,y_a,y_aa,t_0,h);
	return (y_0 + m*h);
}

