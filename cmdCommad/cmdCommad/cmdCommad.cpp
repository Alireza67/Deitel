// cmdCommad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <Windows.h>

std::string exec(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

int main()
{
	/*std::string getIP =  exec("ping 169.254.61.251");
	std::string getStat =  exec("netstat -p udp -a -o");
	std::cout << "\n"<<getIP<<"\n";
	std::cout << "\n"<< getStat <<"\n";*/

	//std::string pingStr = (std::string) "netstat -p udp -o -n -a | findstr 0.0:1200";
	//while (true)
	//{
	//	bool resultCmd = !(bool)std::system(pingStr.c_str());
	//	std::cout << "\n" << resultCmd;
	//	Sleep(100);
	//	std::system("cls");
	//}

	std::string pingStr = (std::string) "netstat -p udp -o -n -a | findstr 0.0:1200";
	std::string getStat = exec("netstat -p udp -o -n -a | findstr 0.0:1200");
	if (getStat.empty())
		std::cout << "\nport 1200 is Ready for your program!\n";
	else
		std::cout << "\nport 1200 is Busy!!!!\nPlease Close Other Similar Softwares!";



	
}
