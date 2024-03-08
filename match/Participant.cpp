#include "Participant.h"

Participant::Participant(string name, string gender): name(name), gender(gender) {
}

Participant::~Participant() {
	cout << "Participant destroyed.\n";
}

string Participant::getName() {
	return this->name;
}

void Participant::setName(string name) {
	this->name = name;
}

string Participant::getGender() {
	return this->gender;
}

void Participant::setGender(string gender) {
	this->gender = gender;
}

string Participant::toString() {
	return "Name: " + this->name + "\nGender: " + this->gender;
}
