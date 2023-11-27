#include "headers.h"

Person::Person() : name(""), city(""), age(0) {}

Person::Person(string name, string city, int age) {
	this->name = name;
	this->city = city;
	this->age = age;
}

string Person::getName() {
	return name;
}

void Person::setName(string name) {
	this->name = name;
}

string Person::getcity() {
	return city;
}

void Person::setCity(string city) {
	this->city = city;
}

int Person::getAge() {
	return age;
}

void Person::setAge(int age) {
	this->age = age;
}

string Person::toString() {
	return this->name + " living in " + this->city + ".";
}

bool Person::operator==(Person& other) {
	return this->name == other.name && this->city == other.city && this->age == other.age;
}

bool Person::operator!=(Person& other) {
	return this->name != other.name || this->city != other.city || this->age != other.age;
}

Person::~Person() {
	cout << "destroying " + this->name + " who is living in " + this->city << endl;
}
