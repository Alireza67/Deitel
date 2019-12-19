#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


int main()
{
	std::ofstream File{ "newFile.txt", std::ios::out };
	if (!File)
	{
		std::cerr << "File is not opened!\n";
		exit(EXIT_FAILURE);
	}
	
}

