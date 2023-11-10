#include "functions.h"


// Get the icecreams names
void getNames(string tempArr[], int array_length) {
	for (int i = 0; i < array_length; i++) {
		getline(cin, tempArr[i]);
	}
}


// Get the score for each icecream.
void getScores(string icecreams[], float icecreamsScores[], int totalAmount) {
	string theInput;

	for (int i = 0; i < totalAmount; i++) {
		cout << icecreams[i] << ": ";
		getline(cin, theInput);
		if (theInput != "") {
			icecreamsScores[i] += stof(theInput);
		} else icecreamsScores[i] += 0.0;
	}
}


string* readFile() {
	int rowCount = 0;
	string rowContent;

	ifstream inStream("db.txt", ios::binary);
	if (inStream.is_open()) {
		cout << "ttt ";
		inStream.seekg(0, ios_base::end);
		inStream.seekg(0, ios_base::beg);

		cout << "position 1 : " << inStream.tellg() << endl;
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


		for (size_t i = 0; i < rowCount; i++) {
			cout << "arr " << tempArray[i] << endl;
		}

		

		return tempArray;
	}
	else {
		string* message = new string[1]{"Could not read the file."
	};
		return message;
	}

	/*string theLine;
	if (inStream.is_open()) {
		int counter = 0;

		int index = 0;
		while (getline(inStream, theLine)) {
			tempArray[index] = theLine;
			index++;
		}
		inStream.close();
	}*/
}


vector<string> readFile2() {
	ifstream inStream;
	vector <string> tempArr;
	inStream.open("db.txt");

	string theLine;
	if (inStream.is_open()) {
		int counter = 0;

		string* tempArray = new string[10000];
		int index = 0;
		while (getline(inStream, theLine)) {
			tempArr.push_back(theLine);
			index++;
		}
		inStream.close();
	}
	return tempArr;
}