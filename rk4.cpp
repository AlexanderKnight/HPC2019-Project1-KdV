#include "kdv.h"
#include <iostream>

double* k(double *y, double *k, int size, double deltaX, double h)
{
	printf("Starting k function");
	double y_new[size];
	for (int i=0;i<size;i++){
		double y_i;
		int *near;
		near=checkBounds(i,size);
		y_i = y[i]+k[i]*h;
		y_new[i]=func(k[near[0]],k[near[1]],y_i,k[near[3]],k[near[4]],deltaX);
	}
	return y_new;
}

/*
double* k1(double *y, double deltaX)
{
	double* y_new[size];
	for (int i=0;i<size;i++){
		int* neighbors[5]; 
		int near=checkBounds(i,size);
		y_new[i]=func(y[near[0]],y[near[1]],y[near[2]],y[near[3]],y[near[4]],deltaX);
	}
	return y_new;
}

double* k2(double *y, double *k1, double deltaX, double h)
{
	double* y_new[size];
	for (int i=0;i<size;i++){
		double y_i;
		int near=checkBounds(i,size);
		y_i = y[i]+k1[i]*(h/2.);
		y_new[i]=func(k1[near[0]],k1[near[1]],y_i,k1[near[3]],k1[near[4]],deltaX);
	}
	return y_new;
}

// Previous code is "done". Next code needs work.
double k3(double *y, double *k2, double deltaX, double h)
{
	double* y_new[size];
	for (int i=0;i<size;i++){
		double y_i;
		int near=checkBounds(i,size);
		y_i = y[i]+k2[i]*(h/2.);
		y_new[i]=func(k2[near[0]],k2[near[1]],y_i,k2[near[3]],k3[near[4]],deltaX);
	}
	return y_new;
}

double k4(double y_bb, double y_b, double y_0,
	       double y_a, double y_aa, double deltaX, double h)
{
	double y = y_0 + k3(y_bb,y_b,y_0,y_a,y_aa,deltaX,h)*h;
	return func(y_bb,y_b,y,y_a,y_aa,deltaX);
}
*/
double* rk4(double* y, int size, double deltaX, double h)
{
	printf("Starting rk4\n");
	double y_new[size];
	double *k1;
	double *k2;
	double *k3;
	double *k4;
	printf("Made arrays, making k1's\n");
	k1 = k(y, y, size, deltaX, 0.);
	printf("Made arrays, making k2's\n");
	k2 = k(y, k1, size, deltaX, h/2.);
	k3 = k(y, k2, size, deltaX, h/2.);
	k4 = k(y, k3, size, deltaX, h);
	
	for (int i=0;i<size;i++)
	{
		y_new[i] = y[i]+ h*((1./6.)*k1[i]+(1./3.)*k2[i]+(1./3.)*k3[i]+(1./6.)*k4[i]);
	}
	return y_new;
}

