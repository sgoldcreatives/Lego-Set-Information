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

	if (f.peek() == EOF) {
		cout << "Error: File is empty!";
	}

	while (f >> L.setNum >> L.price >> L.pieces >> L.minifigs) //Loop to read each data value
	{
		std::getline(f, L.setName); //additional function to read set's names

		fileData(f, L, listNum);

	}
}

void openFile(std::string fileName) {

	fstream file;
	file.open(fileName);

	if (file.is_open()) {
		readFile(file);
		closeFile(file);
	}
	else {
		cout << "Error: File not found!" << endl;
	}


}

void closeFile(std::fstream& fClose) {
	fClose.close();
	if (fClose.is_open()) {
		cout << endl << "Error: File not closed";
	}
}

void fileData(std::fstream& fin, legoSet& Lego, int &numList) {

	 // List number
	cout << endl << endl << "List #" << numList << endl
		<< "Set name:" << Lego.setName << endl
		<< "Set number: " << Lego.setNum << endl
		<< "Retail price (USD): $" << Lego.price << endl
		<< "Minifig count: " << Lego.minifigs << endl
		<< "Total piece count: " << Lego.pieces << endl
		<< "Total price per piece: $" << setprecision(Lego.get_deciCount()) << fixed << static_cast<float>(Lego.pieces) / Lego.price << endl;
	numList++;
}