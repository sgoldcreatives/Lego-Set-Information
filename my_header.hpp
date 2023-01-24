#ifndef MY_HEADER_HPP
#define MY_HEADER_HPP
#include <string>
#include <fstream>

void openFile(std::string);

void readFile(std::fstream& f);

class legoSet
{
	const int deciCount = 2;

public:
	int setNum = 0;
	float price = 0;
	int pieces = 0;
	int minifigs = 0;

	int get_deciCount() {
		return deciCount; //Getter to use for function readFile
	}

};


#endif

