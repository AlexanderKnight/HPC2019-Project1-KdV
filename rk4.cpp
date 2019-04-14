#include "kdv.h"
#include <iostream>


void k(double *y, double *ki, int size, double deltaX, double h, int first, double *y_temp)
{
	double y_i [size];
	
	for (int i=0;i<size;i++){
		y_i[i] = y[i]+ki[i]*h;
	}

	for (int i=0;i<size;i++){
		double y_i;
		int near [5];
		near=checkBounds(i,size);

		if( first == 0)
		{
			y_temp[i]=func(y[near[0]],y[near[1]],y_i[i],y[near[3]],y[near[4]],deltaX);
		}
		else
		{
			y_temp[i]=func(ki[near[0]],ki[near[1]],y_i[i],ki[near[3]],ki[near[4]],deltaX);
		}
		
	}
	return y_temp;
}

double* rk4(double* y, int size, double deltaX, double h)
{
	double y_dummy [size];
	double k1 [size];
	double k2 [size];
	double k3 [size];
	double k4 [size];
	double y_new [size];
	//k1 = k(y, y_temp, size, deltaX, 0.);
	k1 = k(y, y_dummy, size, deltaX, 0., 0, y_new);
	k2 = k(y, k1, size, deltaX, h/2., 1, y_new);
	k3 = k(y, k2, size, deltaX, h/2.,1, y_new);
	k4 = k(y, k3, size, deltaX, h,1, y_new);
	
	for (int i=0;i<size;i++)
	{
		y_new[i] = y[i]+ h*((1./6.)*k1[i]+(1./3.)*k2[i]+(1./3.)*k3[i]+(1./6.)*k4[i]);
	}
	return y_new;
}

