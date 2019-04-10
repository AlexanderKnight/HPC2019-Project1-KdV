
#ifndef KDV_H
#define KDV_H

// Include Wtime() for timing
#include <sys/time.h>
#include <stdlib.h>

double func(double y_bb, double y_b,
		double y_0,
		double y_a, double y_aa,
		double deltaX);

/* 4th-Order Runge Kutta
Takes:
- Spacially previous values y_bb=y_(i-2), y_b=y_(i-1)
- the current value y_0=y_(i)
- Spacially post values y_a=y_(i+1), y_aa=y_(i+2)
- distance between points deltaX
- timestep h (t_(i+1)-t_(i))
  Requires EoS function (func) 
  to be defined in this file.*/
double rk4(double y_bb, double y_b,
	double y_0,
	double y_a, double y_aa,
       	double deltaX, double h);

void timestep(double* input, int _size, double t, double dt, double* output);

static inline double Wtime(void)
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_sec + tv.tv_usec / 1e6;
}

static inline int* checkBounds(int cur, int _size)
{

	int solution[5];

	if(cur == 0)
	{
		solution[0] = _size - 2;
		solution[1] = _size - 1;
		solution[2] = cur;
		solution[3] = cur  + 1;
		solution[4] = cur + 2;
	}
	else if( cur == 1)
	{
		solution[0] = _size - 1;
		solution[1] =  0;
		solution[2] = cur;
		solution[3] = cur  + 1;
		solution[4] = cur + 2;
	}
	else
	{
		solution[0] =  cur - 2;
		solution[1] =  cur - 1;
		solution[2] = cur;
		solution[3] =  (cur+ 1) %_size;
		solution[4] = (cur + 2)%_size;
	}

	return solution;
}

#endif
