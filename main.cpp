#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "hanoi.h"

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cout << "Usage:  solver [input file] [output file]" << std::endl;
		return 0;
	}

	std::ifstream fin(argv[1]);
	std::ofstream fout(argv[2]);

	unsigned int n = 0;
	if (!(fin >> n))
	{
		std::cerr << "Invalid input file!" << std::endl;
	}
	else
	{
		Hanoi problem(n);
		problem.Solve(fout);	
	}

	return 0;
}