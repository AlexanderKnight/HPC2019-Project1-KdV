#include "kdv.h"
#include <stdio.h>

/*
   Used to calculate the k array. Parallelization happens here.
   Used for fourth-order runge-kutta.
*/
void k(double *y, double *ki, int size, double deltaX, double h, double *y_temp)
{
	double y_i [size];
#pragma omp parallel for
	for (int i=0;i<size;i++){
		y_i[i] = y[i]+ki[i]*h;
	}

#pragma omp parallel for
	for (int i=0;i<size;i++){
		int *near=checkBounds(i,size);

		y_temp[i]=func(y_i[near[0]],y_i[near[1]],y_i[i],y_i[near[3]],y_i[near[4]],deltaX);
		
	}
}

/*
   Fourth-order runge-kutta.
   Updates the y_new array.
*/
void rk4(double* y, int size, double deltaX, double h, double* y_new)
{
	double k1 [size];
	double k2 [size];
	double k3 [size];
	double k4 [size];
	k(y,  y, size, deltaX,   0., k1);
	k(y, k1, size, deltaX, h/2., k2);
	k(y, k2, size, deltaX, h/2., k3);
	k(y, k3, size, deltaX,    h, k4);

	
#pragma omp parallel for
	for (int i=0;i<size;i++)
	{
		y_new[i] = y[i]+ h*((1./6.)*k1[i]+(1./3.)*k2[i]+(1./3.)*k3[i]+(1./6.)*k4[i]);
	}
}

