#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>
#include <algorithm>
#include "rk4.h"
using namespace std;

//Run command: 
// " ./main [input.txt] [number of data points] "
int main(int argc, char **argv)
{
  // handle too many or few arguments...
	if(argc != 3)
	{
		cerr << "Wrong number of arguments" << endl;
		return 1;
	}

	// Open data file
    string file = argv[1];
	ifstream stream(file.c_str());

	//Set size
	int size = stoi(argv[2]);

	// check if it opened
	if(!stream)
	{
		cerr << "Error opening file" << endl;
		return 1;
	}

	//create data structure


	while( stream)
	{
		//need format of data text file!
	}
	
	stream.close();

  return 0;
}
