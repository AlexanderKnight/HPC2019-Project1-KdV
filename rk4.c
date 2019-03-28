#include "kdv.h"

double k1(double y_0, double t_0)
{
	return func(y_0, t_0);
}

double k2(double y_0, double t_0, double h)
{
	double y = y_0 + k1(y_0,t_0)*(h/2.);
	double t = t_0 + (h/2.);
	return func(y,t);
}

double k3(double y_0, double t_0, double h)
{
	double y = y_0 + k2(y_0, t_0, h)*(h/2.);
	double t = t_0 + (h/2.);
	return func(y,t);
}

double k4(double y_0, double t_0, double h)
{
	double y = y_0 + k3(y_0,t_0,h)*h;
	double t = t_0 + h;
	return func(y,t);
}

double rk4(double y_0, double t_0, double h)
{
	double m = (1./6.)*k1(y_0,t_0)+
			(1./3.)*k2(y_0,t_0,h)+
			(1./3.)*k3(y_0,t_0,h)+
			(1./6.)*k4(y_0,t_0,h);
	return y_0 + m*h;
}

