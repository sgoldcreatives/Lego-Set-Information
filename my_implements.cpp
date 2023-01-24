#include "my_header.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void readFile(std::fstream& f)
{
	legoSet L; //Call class
	int listNum = 1; // List number

	while (f >> L.setNum >> L.price >> L.pieces >> L.minifigs) //Loop to read each data value
	{
		/*Reads the variables in the order that they are written and
		outputs small computational table with all important
		information. Piece count is price per piece and needs to be 
		static casted in order to get amount in usd.*/

		cout << endl << endl << "List #" << listNum << endl << "Set number: " << L.setNum << endl
			<< "Retail price (USD): $" << L.price << endl
			<< "Minifig count: " << L.minifigs << endl
			<< "Total piece count: " << L.pieces << endl
			<< "Total price per piece: $" << setprecision(L.get_deciCount()) << fixed << static_cast<float>(L.pieces) / L.price << endl;
		listNum++;
	}
}

void openFile(std::string fileName) {

	fstream file;
	file.open(fileName);

	if (file.is_open()) {
		readFile(file);
	}
	else {
		cout << "Error: File not found!" << endl;

	}


}