#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "init.h"


int main()
{
//##########################################
// Parameter to change
//##########################################
	int size = 200;
	double start = -5.;
	double end = 5.;
	// Choices are cos, sin, sech, & exp
	// cos: cos((2pi/L)*x)
	// sin: sin((2pi/L)*x)
	// sech: sech^2(x-L/2)
	// exp: exp(-(x-L/2)^2)
	std::string func;
	func = "sech";

//##########################################
// Should not need anything below here
//##########################################


	double dx = (end-start)/(double(size));
	double y[size];

	if (func=="cos"){
		Init_Cos(dx, y, size, start, end);
	}
	else if (func=="sin"){
		Init_Sin(dx, y, size, start, end);
	}
	else if (func=="sech"){
		Init_Sech(dx, y, size, start, end);
	}
	else if (func=="exp"){
		Init_Exp(dx, y, size, start, end);
	}
	else{
		printf("No allowed initial function chosen!!\n");
		return 0;
	}	

	ofstream initData;
	initData.open ("KdVInitData.dat");
	initData << size << "\n" << dx << "\n";
	for (int i=0;i<size;i++){
		initData << y[i] << "\n" << i*dx << "\n";
	}
	initData.close();
	
}	
