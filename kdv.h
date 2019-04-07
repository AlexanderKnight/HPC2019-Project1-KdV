
#ifndef KDV_H
#define KDV_H

// Include Wtime() for timing
#include <sys/time.h>
#include <stdlib.h>

double func(double y_bb, y_b,
		double y_0,
		double y_a, double y_aa,
		double deltaX)

static inline double Wtime(void)
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_sec + tv.tv_usec / 1e6;
}

#endif
