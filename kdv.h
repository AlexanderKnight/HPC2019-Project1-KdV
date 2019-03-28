
#ifndef KDV_H
#define KDV_H

// Include Wtime() for timing
#include <sys/time.h>
#include <stdlib.h>

/* 4th-Order Runge Kutta
  Takes the current value y_0
  at time t_0, and steps forward
  in time by h. 
  Requires EoS function (func) 
  to be defined in this file.*/
double rk4(double y_0, t_0, h);

static inline double Wtime(void)
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_sec + tv.tv_usec / 1e6;
}

#endif
