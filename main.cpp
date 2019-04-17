#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>
#include <algorithm>
#include <cstring>
#include <math.h>
#include "kdv.h"
using namespace std;

/*  Run command: 
*	" ./main [input.txt] "
*
*/ 
int main(int argc, char **argv)
{

//######################################################
// Only parameters that may need manually changed
//######################################################
	//How many iterations do we want to do? 
	int numIter = 1e5;
	//Save every Nth step. In this scale, saving every
	//step usually is too much data.
	//Roughly speaking, 3 orders of magnitude less
	//than numIter is a good starting point.
	int save_every_nth_iter = 1e2;

//######################################################
// Parameters below should not need to be changed
//######################################################

    double start = Wtime();
    // handle too many or few arguments...
	if(argc != 2)
	{
		cerr << "Wrong number of arguments" << endl;
		return 1;
	}

	// Open data file
    string file = argv[1];
	ifstream stream(file.c_str());

	// check if it opened
	if(!stream)
	{
		cerr << "Error opening file" << endl;
		return 1;
	}

	//Read in first double (size)
	string x;
	stream >> x;
	int size = atof(x.c_str());

	//Create double array to hold data points
	double* input = new double[size];
	double* xvals = new double[size];

	//Our time is initially 0 (may or may not need this in this file)
	double time = 0; 

	//Let us now get our deltaX. Should be second line: 

	stream >> x;
	double deltaX = atof(x.c_str());

	//Let us fill out data structure
	int index = 0; 
	while( stream)
	{
		stream >> x;
		double val = atof(x.c_str());

		input[index] = val;

		stream >> x;
		double val1 = atof(x.c_str());
		xvals[index] = val1;
		index += 1;
	}
	// Our input array should now hold all the original values... 

	//We no longer need stream. Let's close this:
	stream.close();
	double fileReadTime = Wtime();

	//I want to timestep through each iteration, but lets make a 2d Array to keep track of all our iterations
	// row 0 will be the first iteration, row 1 will be the second, and so on.
	// our fourth point after the 7th iteration can be found by calling TwoD[7][4]


	//How much time between iterations? Set 0.5 seconds for now...
	double dt = deltaX*deltaX*deltaX;

	//creating 2d array:
	//double TwoD[numIter][size - 1];
	double** TwoD = new double*[numIter];
	for(int i = 0; i < numIter; i++)
	{
		TwoD[i] = new double[size];
	}

	

	//Let us set iteration 0 to input
	TwoD[0] = input; 
	//memcpy(input, TwoD[0], size*sizeof(double));
	//for(int i = 0; i < 20; i++)
	//{
		//cout << TwoD[0][i] << endl;
	//}

	//call timestep using the previous iteration from 1 to numIter...
	for(int i = 1; i < numIter; i++)
	{
		rk4(TwoD[i-1], size, deltaX, dt, TwoD[i]);
		//memcpy(timestep(TwoD[i-1], size, deltaX, dt), TwoD[i], size*sizeof(double));
	}
	double calcTime = Wtime();

	
	//We now have a 2d Array with all iterations!

	//EvolvedData.dat written to be optimized for
	//gnuplot, which makes plots faster than most
	//othe plotting sources.
    	string filename = "EvolvedData.dat";
	ofstream datafile;
	datafile.open(filename .c_str());
	for (int j=0;j<size;j++){
		for (int i=0;i<numIter;i=i+save_every_nth_iter){
			datafile << " " << TwoD[i][j];
		}
		datafile << "\n";
	}
	datafile.close();
	double fileWriteTime = Wtime();
	printf("File read in: %g\n",fileReadTime-start);
	printf("Calc time in: %g\n",calcTime-start);
	printf("File written: %g\n",fileWriteTime-start);
	return 0;

}
