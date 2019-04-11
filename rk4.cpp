#include "kdv.h"
#include <iostream>


double* k(double *y, double *ki, int size, double deltaX, double h)
{
	double y_new[size];
	for (int i=0;i<size;i++){
		double y_i;
		int *near = new int[5];
		near=checkBounds(i,size);
		y_i = y[i]+ki[i]*h;
		y_new[i]=func(ki[near[0]],ki[near[1]],y_i,ki[near[3]],ki[near[4]],deltaX);
	}
	return y_new;
}

double* rk4(double* y, int size, double deltaX, double h)
{
	double y_new[size];
	double *k1 = new double[size];
	double *k2 = new double[size];
	double *k3 = new double[size];
	double *k4 = new double[size];
	k1 = k(y, y, size, deltaX, 0.);
	printf("done with k1\n");
	for (int i=0;i<size;i++){
		printf("%g, ",k1[i]);
	}
	printf("\n");
	k2 = k(y, k1, size, deltaX, h/2.);
	printf("done with k2\n");
	k3 = k(y, k2, size, deltaX, h/2.);
	printf("done with k3\n");
	k4 = k(y, k3, size, deltaX, h);
	printf("done with k4\n");
	
	printf("Assigning new values\n");
	for (int i=0;i<size;i++)
	{
		y_new[i] = y[i]+ h*((1./6.)*k1[i]+(1./3.)*k2[i]+(1./3.)*k3[i]+(1./6.)*k4[i]);
	}
	printf("done assigning new values\n");
	return y_new;
}

