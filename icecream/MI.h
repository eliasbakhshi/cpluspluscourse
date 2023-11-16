#pragma once
#include "headers.h"

// Class for managing inputs
class MI : private MS{

public:
	string get_string(string message = "", bool acceptEmptyString = false);
	int get_int(string message);
	float get_float(string message);
};
