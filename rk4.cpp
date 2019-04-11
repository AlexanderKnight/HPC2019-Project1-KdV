#include "kdv.h"
#include <iostream>


double* k(double *y, double *ki, int size, double deltaX, double h, int first)
{
	double *y_temp = new double[size];
	for (int i=0;i<size;i++){
		double y_i;
		int *near = new int[5];
		near=checkBounds(i,size);

		if( first == 0)
		{
			y_i = y[i]+ki[i]*h;
			y_temp[i]=func(y[near[0]],y[near[1]],y_i,y[near[3]],y[near[4]],deltaX);
		}
		else
		{
			y_i = y[i]+ki[i]*h;
			y_temp[i]=func(ki[near[0]],ki[near[1]],y_i,ki[near[3]],ki[near[4]],deltaX);
		}
		
	}
	return y_temp;
}

double* rk4(double* y, int size, double deltaX, double h)
{
	double *y_dummy = new double[size];
	double *k1 = new double[size];
	double *k2 = new double[size];
	double *k3 = new double[size];
	double *k4 = new double[size];
	//k1 = k(y, y_temp, size, deltaX, 0.);
	k1 = k(y, y_dummy, size, deltaX, 0., 0);
	k2 = k(y, k1, size, deltaX, h/2., 1);
	k3 = k(y, k2, size, deltaX, h/2.,1);
	k4 = k(y, k3, size, deltaX, h,1);
	
	double *y_new = new double[size];
	for (int i=0;i<size;i++)
	{
		y_new[i] = y[i]+ h*((1./6.)*k1[i]+(1./3.)*k2[i]+(1./3.)*k3[i]+(1./6.)*k4[i]);
	}
	return y_new;
}

