#include "Elit.h"

Elit::Elit(string name, string gender, string club, int seasonNum) :Participant(name, gender), club(club), seasonNum(seasonNum) {}

//Elit::Elit(Elit& other) : Participant(other), club(other.club), seasonNum(other.seasonNum) {}
//
//void Elit::operator=(Elit& other) {
//	//Participant(other);
//	this->club = other.club;
//	this->seasonNum = other.seasonNum;
//}

Elit::~Elit() {
	cout << "Elit destroyed.\n";
}

string Elit::getClub() {
	return this->club;
}

void Elit::setClub() {
	this->club = club;
}

int Elit::getSeasonNum() {
	return this->seasonNum;
}

void Elit::setSeasonNum(int seasonNum) {
	this->seasonNum = seasonNum;
}

bool Elit::contains(string str) const {
	cout << str << endl;
	return false;
}


string Elit::toString() {
	return "Season number: " + this->seasonNum + this->club;
}

Elit* Elit::clone() {
	return new Elit(*this);
}
