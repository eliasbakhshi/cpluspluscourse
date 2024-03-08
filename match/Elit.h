#pragma once
#include "Headers.h"
#include "Participant.h"

class Elit : public Participant {
	string club;
	int seasonNum = 0;

public:
	Elit(string name, string gender, string club, int seasonNum);
	//Elit(Elit& other);
	//void operator=(Elit& other);
	~Elit();
	string getClub();
	void setClub();
	int getSeasonNum();
	void setSeasonNum(int seasonNum);
	bool contains(string str) const override;
	string toString() override;
	Elit* clone();
};

