#include "kdv.h"
#include <iostream>


void k(double *y, double *ki, int size, double deltaX, double h, int first, double* y_temp)
{
        double y_i[size];
	for (int i=0;i<size;i++){
	  y_i[i] = y[i]+ki[i]*h;
	}
	for (int i=0;i<size;i++){
		int *near=checkBounds(i,size);

		//		printf("%d %d %d %d %d\n", near[0], near[1], near[2], near[3], near[4]);
		y_temp[i]=func(y_i[near[0]],y_i[near[1]],y_i[i],y_i[near[3]],y_i[near[4]],deltaX);
	}
}

void rk4(double* y, int size, double deltaX, double h, double* y_new)
{
        double y_dummy[size];
	double k1[size];
	double k2[size];
	double k3[size];
	double k4[size];
	//k1 = k(y, y_temp, size, deltaX, 0.);
	k(y, y_dummy, size, deltaX, 0., 0, k1);
	k(y, k1, size, deltaX, h/2., 1, k2);
	k(y, k2, size, deltaX, h/2.,1, k3);
	k(y, k3, size, deltaX, h,1, k4);

	{
	  FILE *f = fopen("k1.asc", "w");
	  for (int i=0;i<size;i++)
	    {
	      fprintf(f, "%g %g\n", i*deltaX, k1[i]);
	    }
	  fclose(f);
	}

	for (int i=0;i<size;i++)
	  {
	    y_new[i] = y[i]+ h*((1./6.)*k1[i]+(1./3.)*k2[i]+(1./3.)*k3[i]+(1./6.)*k4[i]);
	  }

	  static int cnt;
	char fname[100];
	if (cnt++ % 1000) {
	  sprintf(fname, "y-%d.asc", cnt);
	  FILE *f = fopen(fname, "w");
	  for (int i=0;i<size;i++)
	    {
	      fprintf(f, "%g %g %g\n", i*deltaX, y_new[i], y[i]);
	    }
	  fclose(f);
	}
	printf("rk4 done\n");
}

