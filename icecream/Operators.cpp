#include "headers.h"

void operators() {
	Operators t1(4, 5), t2(2, 3), t3;
	t3 = t1 + t2;

	cout << t3.getNum1() << endl;
	cout << t3.getNum2() << endl;
}



Operators::Operators(int n1, int n2) {
	num1 = n1;
	num2 = n2;
}


Operators Operators::operator+(Operators& obj) {
	Operators t3;
	if (this != &obj) {
		t3.num1 = num1 + obj.num1;
		t3.num2 = num2 + obj.num2;
	}
	return t3;
}

Operators Operators::operator*(Operators& obj) {
	Operators t3;
	if (this != &obj) {
		t3.num1 = num1 * obj.num1;
		t3.num2 = num2 * obj.num2;
	}
	return t3;
}

int Operators::getNum1() {
	return num1;
}
int Operators::getNum2() {
	return num2;
}
