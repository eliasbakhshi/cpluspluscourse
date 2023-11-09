#include "Test.h"
#include <fstream>
using namespace std;
string returningText() {
	return "This is the text";
}

int readFromFile(string filename) {
	int readInteger = -1;
	ifstream in;
	in.open(filename);
	if (in.is_open()) {
		in >> readInteger;
		in.close();
	}
	return readInteger;
}
