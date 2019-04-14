#include "kdv.h"
#include <iostream>


void k(double *y, double *ki, int size, double deltaX, double h, double *y_temp)
{
	double y_i [size];
	for (int i=0;i<size;i++){
		y_i[i] = y[i]+ki[i]*h;
	}

	for (int i=0;i<size;i++){
		int *near=checkBounds(i,size);

			y_temp[i]=func(ki[near[0]],ki[near[1]],y_i[i],ki[near[3]],ki[near[4]],deltaX);
		
	}
}

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
	
	for (int i=0;i<size;i++)
	{
		y_new[i] = y[i]+ h*((1./6.)*k1[i]+(1./3.)*k2[i]+(1./3.)*k3[i]+(1./6.)*k4[i]);
	}
}

