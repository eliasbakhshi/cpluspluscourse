#ifndef BUDDYBOOK_H
#define BUDDYBOOK_H
#include "Buddy.h"

class BuddyBook
{
private:
	Buddy** buddies; // ptrAsArrayOfPtrsToBuddies
	int capacity;
	int currentNrOfBuddies;

	void expand();

public:
	BuddyBook(int capacity = 3);
	~BuddyBook();
	BuddyBook(const BuddyBook& other);

	void addBuddy(string name, int age, float height);
	bool removeBuddy(string name, int age, float height);

	void showBuddies() const;

	void operator=(const BuddyBook& other);
	int getCurrentNrOfBuddies() const;

};

#endif
