#include <cmath>
#include "initFunc.h"

#define sqr(a) ((a)*(a))

#define PI 3.14159265

void Init_Sin(double dx, double* y, int size,
		double start, double end)
{
	for (int i=0; i<size; i++){
		y[i] = sin((2.*PI*dx*i)/(end-start));
	}
}


void Init_Cos(double dx, double* y, int size,
		double start, double end)
{
	for (int i=0; i<size; i++){
		y[i] = cos((2.*PI*dx*i)/(end-start));
	}
}

void Init_Sech(double dx, double* y, int size,
		double start, double end)
{
	for (int i=0; i<size; i++){
		y[i] = 1./sqr(cosh(((end-start)/2.)-dx*i));
	}
}

void Init_Exp(double dx, double*y, int size,
		double start, double end)
{
	for (int i=0; i<size; i++){
		y[i] = exp(-1.*sqr((i*dx-((end-start)/(2.)))));
	}
}
