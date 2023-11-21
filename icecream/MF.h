#pragma once
#include "headers.h"

// Class for managing files
class MF {
	string color = "";

public:
	bool saveToFile(string filename, string names[], float scores[], int length);
	int* countFilerows(string filename);
	string* readFile(string filename);

};