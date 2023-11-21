#pragma once
#include "headers.h"

class Operators{
	int num1 = 0, num2 = 0;
public:
	int getNum1();
	int getNum2();
	Operators(int n1 = 0, int n2 = 0);
	Operators operator+(Operators&);
	Operators operator*(Operators&);


};

