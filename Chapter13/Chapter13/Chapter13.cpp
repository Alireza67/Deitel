#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


int main()
{
	
	try
	{
		std::ofstream File{ "newFile.txt", std::ios::out };
		if (!File)
		{
			std::cerr << "File is not opened!\n";
			exit(EXIT_FAILURE);
		}

		std::cout << "Enter Account, name, and balance.\n";
		int account{};
		std::string name;
		double balance{};

		while (std::cin >> account >> name >> balance)
		{
			File << account << " " << name << " " << balance << std::endl;
			std::cout << "?";
		}
	}
	catch (const std::exception&)
	{

	}
}

