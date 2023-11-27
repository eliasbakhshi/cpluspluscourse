#include "headers.h"

void PersonsList::expand() {
	this->capacity += 10;
	Person** temp = new Person * [this->capacity] {nullptr};
	for (int i = 0; i < this->numPersons; i++) {
		temp[i] = this->theList[i];
	}
	delete[] this->theList;
	this->theList = temp;
}

PersonsList::PersonsList(int capacity) {
	this->theList = new Person * [capacity] {nullptr};
	this->capacity = capacity;
	this->numPersons = 0;
}

PersonsList::PersonsList(const PersonsList& other) : theList(new Person* [other.capacity] {nullptr}), capacity(other.capacity), numPersons(other.numPersons) {
	if (this != &other) {
		for (int i = 0; i < other.numPersons; i++) {
			delete this->theList[i];
		}
		delete[] this->theList;

		this->capacity = other.capacity;
		this->numPersons = other.numPersons;
		this->theList = new Person * [this->capacity] {nullptr};
		for (int i = 0; i < this->numPersons; i++) {
			this->theList[i] = new Person(*other.theList[i]);
		}
	}
}

void PersonsList::operator=(const PersonsList& other) {
	this->theList= new Person * [other.capacity] {nullptr};
	this->capacity = other.capacity;
	this->numPersons = other.numPersons;

	if (this != &other) {
		for (int i = 0; i < other.numPersons; i++) {
			delete this->theList[i];
		}
		delete[] this->theList;

		this->capacity = other.capacity;
		this->numPersons = other.numPersons;
		this->theList = new Person * [this->capacity] {nullptr};
		for (int i = 0; i < this->numPersons; i++) {
			this->theList[i] = new Person(*other.theList[i]);
		}
	}
}

PersonsList::~PersonsList() {
	for (int i = 0; i < this->numPersons; i++) {
		delete this->theList[i];
	}
	delete[] this->theList;
	cout << "The list has been destroyed" << endl;
}

void PersonsList::addPerson(string name, string city, int age) {
	if (this->numPersons == this->capacity) {
		expand();
	}
	this->theList[numPersons++] = new Person(name, city, age);
}


void PersonsList::showPersons() {
	for (int i = 0; i < this->numPersons; i++) {
		cout << this->theList[i]->toString() << endl;
	}
}

bool PersonsList::removePerson(string name, string city, int age) {
	Person temp(name, city, age);
	bool removed = false;
	for (int i = 0; i < this->numPersons; i++) {
		if (temp == *this->theList[i]) {
			delete this->theList[i];
			this->theList[i] = this->theList[--this->numPersons];
			this->theList[this->numPersons] = nullptr;
			removed = true;
		}
	}

	temp.setName("Moved " + temp.getName());
	return removed;
}

int PersonsList::getCurrentNrOfPersons() const {
	return numPersons;
}
