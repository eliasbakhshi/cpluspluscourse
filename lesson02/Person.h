#pragma once
#include "headers.h"

class Person {
	string name, city;
	int age;
public:
	Person();
	Person(string name, string city, int age);
	~Person();
	string getName();
	void setName(string name);
	string getcity();
	void setCity(string city);
	int getAge();
	void setAge(int age);
	string toString();

	bool operator==(Person& other);
	bool operator!=(Person& other);

};