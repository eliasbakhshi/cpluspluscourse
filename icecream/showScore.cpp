#include "functions.h"

/* Show the scores for the icecreams. */
void showScore() {
	// initialization of the variables
	int* rowsCount = nullptr;
	string* icecreamsList = nullptr, * tempIcecream = nullptr;
	string filename = "db.txt";

	rowsCount = countFilerows(filename);
	icecreamsList = readFile(filename);

	cout << "<-- Here is the list --> " << endl;

	for (int i = 0; i < *rowsCount; i++) {
		tempIcecream = splitString(icecreamsList[i], '|');
		cout << "name: " << tempIcecream[0] << " and the score is " << tempIcecream[1] << endl;
	}

	delete rowsCount;
	delete[] icecreamsList;
	delete[] tempIcecream;
}