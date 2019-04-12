#include "kdv.h"
#include <iostream>

/*
 Argument 1: input is an array double that had the old solutions needing to be timestepped
 Argument 2: _size is an int refering to size of the input Array
 Argument 3: t is a double refering to the current timestep
 Argument4: dt is a double refering to the change in t. This should be constant. 
 */


void timestep(double* input, int _size, double dx, double dt, double* output)
{

	//Logic to prevent domain errors grabbing i-1 and i-2 data points & for loop to update output array
	//int backOne, backTwo;
        rk4(input, _size, dx, dt, output);
/*
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
		output[i] = rk4( input[backTwo], input[backOne], input[(i)], input[(i+1)%_size], input[(i+2)%_size], dx, dt );
	}
*/
//	return output; 
}
