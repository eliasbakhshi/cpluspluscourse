#pragma once
#include "headers.h"

string* MF::readFile(string filename) {
	int rowCount = 0;
	string rowContent;

	ifstream inStream(filename);
	if (inStream.is_open()) {
		while (getline(inStream, rowContent)) { // Get the amount of rows.
			if (!rowContent.empty()) {
				rowCount++;
			}
		}
		inStream.clear();
		inStream.seekg(0, ios_base::beg);

		string* tempArray = new string[rowCount];
		for (int i = 0; i < rowCount; i++) {
			getline(inStream, tempArray[i]);
		}
		inStream.close();
		return tempArray;
	} else {
		string* message = new string[1]{ "Could not read the file." };
		return message;

	}
}

int* MF::countFilerows(string filename) {
	int* rowNums = new int(0);
	string tempInput;
	ifstream theFile(filename);
	if (theFile.is_open()) {
		while (getline(theFile, tempInput)) {
			if (!tempInput.empty())
				*rowNums = *rowNums + 1;
		}
		theFile.close();
		return rowNums;
	}
	return 0;
}

bool MF::saveToFile(string filename, string names[], float scores[], int length) {
	ofstream of(filename);
	string test, test2;
	if (of.is_open()) {
		string word;
		for (int i = 0; i < length; i++) {
			of << names[i] << '|' << scores[i] << endl;
		}
		return true;
	}
	return false;
}


