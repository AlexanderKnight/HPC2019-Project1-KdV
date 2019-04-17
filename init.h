
#ifndef INITFUNC_H
#define INITFUNC_H

#define PI 3.14159265

void Init_Sin(double dx, double* y, int size,
		double start, double end);

void Init_Cos(double dx, double* y, int size,
		double start, double end);

void Init_Sech(double dx, double* y, int size,
		double start, double end);

void Init_Exp(double dx, double* y, int size,
		double start, double end);
#endif
