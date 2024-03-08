#pragma once
#include "Headers.h"
#include "Participant.h"

class Exerciser : public Participant{
	int age;

public:
	Exerciser(string name, string gender, int age);
	//Exerciser(Exerciser& other);
	//void operator=(Exerciser& other);
	~Exerciser();
	int getAge();
	void setAge(int age);
	bool contains(string str) const override;
	string toString() override;

};

