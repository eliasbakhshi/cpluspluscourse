#include "functions.h"

/* Show the scores for the icecreams. */
void showScore() {
	// initialization of the variables
	int* rowsCount = nullptr;
	string* icecreamsList = nullptr, * tempIcecream = nullptr;
	string filename = "db.txt";

	rowsCount = countFilerows(filename);
	icecreamsList = readFile(filename);

	cout << "\n<-- Here is the list --> \n\n";

	for (int i = 0; i < *rowsCount; i++) {
		tempIcecream = splitString(icecreamsList[i], '|');
		cout << tempIcecream[0] << " has the score " << tempIcecream[1] << ". \n";
	}
	cout << endl;

	delete rowsCount;
	delete[] icecreamsList;
	delete[] tempIcecream;
}