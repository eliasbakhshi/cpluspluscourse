#include "functions.h"

string* readFile() {
	ifstream inStream;
	inStream.open("db.txt");
	string theLine;
	if (!inStream.eof()) {
		getline(inStream, theLine);

		cout << fileInput << endl;

		inStream.close();
	}
}