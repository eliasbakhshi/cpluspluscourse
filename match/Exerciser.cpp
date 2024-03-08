#include "Exerciser.h"

Exerciser::Exerciser(string name, string gender, int age) :Participant(name, gender), age(age) {
	cout << "Exerciser created.\n";
}

//Exerciser::Exerciser(Exerciser& other) :age(other.age), Participant(other) {
//	cout << "Exerciser created.\n";
//}

//void Exerciser::operator=(Exerciser& other) {
//	this->age = other.age;
//	//Participant(other);
//}

Exerciser::~Exerciser() {
	cout << "Exerciser destroyed.\n";
}

int Exerciser::getAge() {
	return this->age;
}

void Exerciser::setAge(int age) {
	this->age = age;
}

bool Exerciser::contains(string str) const {
	cout << str << endl;
	return false;
}

string Exerciser::toString() {
	return "Age: " + this->age;
}
