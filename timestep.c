#include "kdv.h"

/*
 Argument 1: input is an array double that had the old solutions needing to be timestepped
 Argument 2: _size is an int refering to size of the input Array
 Argument 3: t is a double refering to the current timestep
 Argument4: dt is a double refering to the change in t. This should be constant. 
 */


double* timestep(double* input, int _size, double t, double dt)
{
	//Array to be outputted
	double *output = new double[_size];

	//Logic to prevent domain errors grabbing i-1 and i-2 data points & for loop to update output array
	int backOne, backTwo;

	#pragma omp parallel for
	for(int i = 0; i < _size; i++)
	{
		if(i == 0)
		{
			backOne = _size - 1;
			backTwo = _size - 2;
		}
		else if( i == 1)
		{
			backOne = 0;
			backTwo = _size - 1;
		}
		else
		{
			backOne = i - 1;
			backTwo = i - 2;
		}

		// input: 5 data points for the i'th point
		output[i] = rk4( input[(i+2)%_size], input[(i+1)%_size], input[(i)], input[backOne], input[backTwo], t, dt );
	}

	return output; 
}