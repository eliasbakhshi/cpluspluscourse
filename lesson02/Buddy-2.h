#ifndef BUDDY_H
#define BUDDY_H
#include <string>
#include <iostream>

using namespace std;

class Buddy
{
public: // public member functions (getters and setters) to access or modify private variables
	// this way, you can enforce certain rules or perform validation when interacting with these
	// variables, maintaning the integrity of the class
	Buddy();
	Buddy(string name, int age, float height);
	~Buddy();

	void setName(string name);
	void setAge(int age);
	void setHeight(float height);
	
	string getName();
	int getAge();
	float getHeight();

	string toString();

	bool operator==(Buddy& otherBuddy);
	bool operator!=(Buddy& otherBuddy);


private: // restrict direct access from outside the class 
// and ensure better control over how the data is manipulated
	string name;
	int age;
	float height;

};

#endif
