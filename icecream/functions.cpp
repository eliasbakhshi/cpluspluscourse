#include "functions.h"



//check if number or string
bool is_number(string str) {
	if (str == "") return false;
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

// Get the icecreams names
void getNames(string tempArr[], int array_length) {
	cout << endl << "Please enter the icecreams' name. Each row for one icecream: \n";
	for (int i = 0; i < array_length; i++) {
		getline(cin, tempArr[i]);
	}
}

string* splitString(string str, char ch = ' ') {
	int count = 1;
	string tempStr = "";
	string* splited = nullptr;
	// Count have many of char exists in the string
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ch) count++;
	}

	splited = new string[count];
	if (count == 1) {
		splited[0] = str;
	} else {
		int j = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ch) {
				splited[j] += str[i];
			} else {
				j++;
			}
		}
	}
	return splited;
}

string get_string(string message, bool acceptEmptyString) {
	string theInput;
	cout << message;
	getline(cin, theInput);
	if (!acceptEmptyString && theInput == "") {
		cout << "You need to give me a string.\n";
		return get_string(message);
	} else if (!is_number(theInput)) {
		return theInput;
	} else {
		cout << "You need to give me a string.\n";
		return get_string(message);
	}

	return "";
}

int get_int(string message) {
	string theInput;
	cout << message;
	getline(cin, theInput);
	if (is_number(theInput)) {
		return stoi(theInput);
	} else {
		cout << "You need to give me a number.\n";
		return get_int(message);
	}
	return 0;
}

float get_float(string message) {
	string theInput;
	cout << message;
	getline(cin, theInput);
	if (is_number(theInput)) {
		return stof(theInput);
	} else {
		cout << "You need to give me a number.\n";
		return get_float(message);
	}
	return 0;
}

// Get the score for each icecream.
void getScores(string icecreams[], float icecreamsScores[], int totalAmount) {
	string theInput;
	for (int i = 0; i < totalAmount; i++) {
		icecreamsScores[i] += get_float("Score for " + icecreams[i] + ": ");
	}
}


string* readFile(string filename) {
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

int* countFilerows(string filename) {
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

bool saveToFile(string filename, string names[], float scores[], int length) {
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