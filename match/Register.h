#pragma once
#include "Headers.h"
#include "Participant.h"
#include "Elit.h"


class Register {
private:
	Participant** participants{ nullptr };
	int capacity = 0, currentNum = 0;
	void expand();
	
public:
	Register(int capacity = 10);
	Register(const Register& other);
	void operator=(const Register& other);
	~Register();
	string toString();
	bool addElit(string name, string gender, string club, int seasonNum);
	bool addExerciser(string name, string gender, int age);
	void showParticipants();
	void searchByName(string name);
	int getCurrentNum();

};

