
#ifndef KDV_H
#define KDV_H

// Include Wtime() for timing
#include <sys/time.h>
#include <stdlib.h>

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

static inline double Wtime(void)
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_sec + tv.tv_usec / 1e6;
}

#endif
