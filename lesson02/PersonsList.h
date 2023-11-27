#pragma once
#include "headers.h"

class PersonsList {
	Person** theList;
	int capacity;
	int numPersons;

	void expand();

public:
	PersonsList(int capacity = 5);
	PersonsList(const PersonsList& other);
	~PersonsList();
	void showPersons();
	void addPerson(string name, string city, int age);
	bool removePerson(string name, string city, int age);
	void operator=(const PersonsList& other);
	int getCurrentNrOfPersons() const;
};

