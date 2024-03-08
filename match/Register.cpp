#include "Register.h"
#include "Exerciser.h"

void Register::expand() {
	this->capacity += 10;
	Participant** tempParti = new Participant * [this->capacity] { nullptr };
	for (size_t i = 0; i < this->currentNum; i++) {
		tempParti[i] = this->participants[i];
		//delete this->participants[i];
	}
	delete[] this->participants;
	this->participants = tempParti;
}

Register::Register(int capacity) :capacity(capacity){
	cout << "Register created.\n";	
	this->participants = new Participant * [10] {nullptr};
	this->currentNum = currentNum;
}

Register::Register(const Register& other) {
	if (&other != this) {
		for (int i = 0; i < this->currentNum; i++) {
			delete this->participants[i];
		}
		delete[] this->participants;
		this->capacity = other.capacity;
		this->currentNum = other.currentNum;
		this->participants = new Participant * [this->capacity] {nullptr};
		for (int i = 0; i < other.currentNum; i++) {
			Exerciser* exerciserPtr = dynamic_cast<Exerciser*>(other.participants[i]);
			if (exerciserPtr != nullptr) {
				this->participants[i] = new Exerciser(*exerciserPtr);
			} else {
				Elit* elitPtr = dynamic_cast<Elit*>(other.participants[i]);
				if (elitPtr != nullptr) {

					this->participants[i] = new Elit(*elitPtr);
				}
			}
		}
	}
}

void Register::operator=(const Register& other) {
	if (&other != this) {
		for (int i = 0; i < this->currentNum; i++) {
			delete this->participants[i];
		}
		delete[] this->participants;
		this->capacity = other.capacity;
		this->currentNum = other.currentNum;
		this->participants = new Participant * [this->capacity] {nullptr};
		for (int i = 0; i < other.currentNum; i++) {
			Exerciser* exerciserPtr = dynamic_cast<Exerciser*>(other.participants[i]);
			if (exerciserPtr != nullptr) {
				exerciserPtr->contains("20");
				this->participants[i] = new Exerciser(*exerciserPtr);
			} else {
				Elit* elitPtr = dynamic_cast<Elit*>(other.participants[i]);
				if (elitPtr != nullptr) {
					elitPtr->contains("Bakhshi");
					this->participants[i] = new Elit(*elitPtr);
				}
			}
		}
	}
}

Register::~Register() {
	cout << "Register destroyed.\n";
}

string Register::toString() {
	return string();
}

bool Register::addElit(string name, string gender, string club, int seasonNum) {
	bool added = false;
	if (this->currentNum == this->capacity) {
		expand();
	}
	this->participants[currentNum++] = new Elit(name, gender, club, seasonNum);
	return added;
}

bool Register::addExerciser(string name, string gender, int age) {
	bool added = false;
	if (this->currentNum == this->capacity) {
		expand();
	}
	cout << "added exerciser" << endl;
	this->participants[this->currentNum++] = new Exerciser(name, gender, age);

	return added;
}

void Register::showParticipants() {
	for (int i = 0; i < this->currentNum; i++) {
		Exerciser* exerciserPtr = dynamic_cast<Exerciser*>(this->participants[i]);
		if (exerciserPtr != nullptr) {
			cout << exerciserPtr->getName() << "  " << exerciserPtr->getGender() << "  " << exerciserPtr->getAge() << endl;
		} else {
			Elit* elitPtr = dynamic_cast<Elit*>(this->participants[i]);
			if (elitPtr != nullptr) {
				cout << elitPtr->getName() << "  " << elitPtr->getGender() << "  " << elitPtr->getClub() << "  " << elitPtr->getSeasonNum() << endl;
			}
		}
	}
}

void Register::searchByName(string name) {
	for (int i = 0; i < this->currentNum; i++) {
		if (this->participants[i]->getName() == name) {
			Exerciser* exerciserPtr = dynamic_cast<Exerciser*>(this->participants[i]);
			if (exerciserPtr != nullptr) {
				cout << exerciserPtr->getName() << "  " << exerciserPtr->getGender() << "  " << exerciserPtr->getAge() << endl;
			} else {
				Elit* elitPtr = dynamic_cast<Elit*>(this->participants[i]);
				if (elitPtr != nullptr) {
					cout << elitPtr->getName() << "  " << elitPtr->getGender() << "  " << elitPtr->getClub() << "  " << elitPtr->getSeasonNum() << endl;
				}
			}
		}
	}
}

int Register::getCurrentNum() {
	return currentNum;
}

