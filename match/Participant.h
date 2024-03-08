#pragma once
#include "Headers.h"

class Participant {
private:
	string name, gender;

public:
	Participant(string name = "", string gender ="");
	virtual ~Participant();
	virtual bool contains(string str) const = 0;
	string getName();
	void setName(string name);
	string getGender();
	void setGender(string gender);
	virtual string toString();
};

