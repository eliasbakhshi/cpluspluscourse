#include "header.h"

void BuddyBook::expand()
{
	this->capacity += 10; // 13
	Buddy** temp = new Buddy* [this->capacity] {nullptr};

	for (int i = 0; i < this->currentNrOfBuddies; i++) // 3
	{
		temp[i] = this->buddies[i];
	}
	delete[] this->buddies;
	this->buddies = temp; // buddies[13]
}

BuddyBook::BuddyBook(int capacity): capacity(capacity), currentNrOfBuddies(0), buddies(new Buddy*[capacity]{nullptr})
{

}

BuddyBook::~BuddyBook()
{
	for (int i = 0; i < this->currentNrOfBuddies; i++)
	{
		delete this->buddies[i];
	}
	delete[] this->buddies;
}

BuddyBook::BuddyBook(const BuddyBook& other): capacity(other.capacity), currentNrOfBuddies(other.currentNrOfBuddies), buddies(new Buddy* [other.capacity] {nullptr})
{
	for (int i = 0; i < this->currentNrOfBuddies; i++)
	{
		this->buddies[i] = new Buddy(*other.buddies[i]);
	}
}

void BuddyBook::addBuddy(string name, int age, float height)
{
	if (this->currentNrOfBuddies == this->capacity)
	{
		expand();
	}
	this->buddies[this->currentNrOfBuddies++] = new Buddy(name, age, height);

}

bool BuddyBook::removeBuddy(string name, int age, float height)
{
	Buddy tempBuddy(name, age, height);

	bool didRemove = false;

	for (int i = 0; i < this->currentNrOfBuddies; i++)
	{
		if (tempBuddy == *this->buddies[i])
		{
			delete this->buddies[i]; //delete 1
			this->buddies[i] = this->buddies[--this->currentNrOfBuddies];
			// 1) we decrease currentNrOfBuddies 4->3
			// 2) assign the last element[3] of the array to our current index [1]

			this->buddies[this->currentNrOfBuddies] = nullptr;
			// Current index and last index are pointing to the asme buddy, 
			// to fix this we set nullptr to the last index
			didRemove = true;
		}
	}
	tempBuddy.setName(tempBuddy.getName() + " temp");

	return didRemove;
}

void BuddyBook::showBuddies() const
{
	for (int i = 0; i < this->currentNrOfBuddies; i++)
	{
		cout << this->buddies[i]->toString() << endl;
	}
}

void BuddyBook::operator=(const BuddyBook& other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->currentNrOfBuddies; i++)
		{
			delete this->buddies[i];
		}
		delete[] this->buddies;
		this->capacity = other.capacity;
		this->currentNrOfBuddies = other.currentNrOfBuddies;
		
		this->buddies = new Buddy* [this->capacity];
		for (int i = 0; i < this->currentNrOfBuddies; i++)
		{
			this->buddies[i] = new Buddy(*other.buddies[i]);
		}

	}
}

int BuddyBook::getCurrentNrOfBuddies() const
{
	return currentNrOfBuddies;
}
