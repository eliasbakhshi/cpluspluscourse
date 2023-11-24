#include "header.h"


bool testBasicFunctionality()
{
	cout << "Testing basic functionality" << endl;
	BuddyBook aBuddyBook;

	if (aBuddyBook.getCurrentNrOfBuddies() != 0)
	{
		cout << "NOT CORRECT amount of buddies, expected 0" << endl;
		return false;
	}
	aBuddyBook.addBuddy("Lisa Land", 23, 167.5f);
	aBuddyBook.addBuddy("Maj Moln", 33, 154.0f);

	if (aBuddyBook.getCurrentNrOfBuddies() != 2)
	{
		cout << "NOT CORRECT amount of buddies, expected 2" << endl;
		return false;
	}
	cout<< "OK: Test basic functionality" << endl;
	return true;
}

bool testRemove()
{
	cout << "Testing remove" << endl;
	BuddyBook aBuddyBook;

	aBuddyBook.addBuddy("Lisa Land", 23, 167.5f);
	aBuddyBook.addBuddy("Maj Moln", 33, 154.0f);
	aBuddyBook.addBuddy("Ralle Regn", 67, 199.5f);
	aBuddyBook.addBuddy("Svenne Snoe", 43, 161.0f);
	//Buddy* ptr = aBuddyBook.getBuddyAt(3);

	aBuddyBook.removeBuddy("Maj Moln", 33, 154.0f);
	if (aBuddyBook.getCurrentNrOfBuddies() != 3)
	{
		cout << "NOT CORRECT amount of buddies, expected 3 " << endl;
		return false;
	}

	aBuddyBook.removeBuddy("Lisa Land", 23, 167.5f);
	if (aBuddyBook.getCurrentNrOfBuddies() != 2)
	{
		cout << "NOT CORRECT amount of buddies, expected 2 " << endl;
		return false;
	}

	aBuddyBook.removeBuddy("Svenne Snoe", 43, 161.0f);
	if (aBuddyBook.getCurrentNrOfBuddies() != 1)
	{
		cout << "NOT CORRECT amount of buddies, expected 1 " << endl;
		return false;
	}

	cout << "OK: Remove" << endl;
	return true;
}

bool testingCopyConstructor()
{
	cout << "Testing copy constructor" << endl;
	BuddyBook bb1;
	BuddyBook bb2(bb1);

	if (bb1.getCurrentNrOfBuddies() != 0)
	{
		cout << "NOT CORRECT amount of buddies" << endl;
		return false;
	}

	bb1.addBuddy("Lisa Land", 23, 167.5f);
	bb1.addBuddy("Maj Moln", 33, 154.0f);
	bb1.addBuddy("Ralle Regn", 67, 199.5f);

	BuddyBook bb3 = bb1;
	if (bb3.getCurrentNrOfBuddies() != 3)
	{
		cout << "NOT CORRECT amount of buddies" << endl;
		return false;
	}
	cout << "OK: Copy Constructor" << endl;
	return true;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	if (!testBasicFunctionality())
	{
		return 1;
	}
	if (!testRemove())
	{
		return 2;
	}
	if (!testingCopyConstructor())
	{
		return 3;
	}
	
	return 0;
}