#include "header.h"

Buddy::Buddy(): name(""), age(0), height(0.0f)
{

}

Buddy::Buddy(string name, int age, float height)
{
	this->name = name;
	this->age = age;
	this->height = height;
}

Buddy::~Buddy()
{
	cout << "Destroying: " << toString() << endl;
}

void Buddy::setName(string name)
{
	this->name = name;
}

void Buddy::setAge(int age)
{
	this->age = age;
}

void Buddy::setHeight(float height)
{
	this->height = height;
}

string Buddy::getName()
{
	return this->name;
}

int Buddy::getAge()
{
	return this->age;
}

float Buddy::getHeight()
{
	return this->height;
}

string Buddy::toString()
{
	return this->name + ", " + to_string(this->age) + ", " + to_string(this->height) + "cm ";
}

bool Buddy::operator==(Buddy& otherBuddy)
{
	return this->name == otherBuddy.name && this->age == otherBuddy.age && this->height == otherBuddy.height;
}
bool Buddy::operator!=(Buddy& otherBuddy)
{
	return this->name != otherBuddy.name || this->age != otherBuddy.age || this->height != otherBuddy.height;
}
// The to_string function is part of the <string> header and is used to
// convert numerical data types to their string representations.
// It creates a string object containting the textual representations of the given numeric
// value