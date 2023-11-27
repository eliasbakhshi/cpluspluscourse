#include "headers.h"


bool testBasicFunctionality()
{
	cout << "Testing basic functionality" << endl;
	PersonsList aPersonsList;

	if (aPersonsList.getCurrentNrOfPersons() != 0)
	{
		cout << "NOT CORRECT amount of buddies, expected 0" << endl;
		return false;
	}
	aPersonsList.addPerson("Lisa Land", "city", 167.5f);
	aPersonsList.addPerson("Maj Moln", "city", 154.0f);

	if (aPersonsList.getCurrentNrOfPersons() != 2)
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
	PersonsList aPersonsList;

	aPersonsList.addPerson("Lisa Land", "city", 167.5f);
	aPersonsList.addPerson("Maj Moln", "city", 154.0f);
	aPersonsList.addPerson("Ralle Regn", "city", 199.5f);
	aPersonsList.addPerson("Svenne Snoe", "city", 161.0f);
	//Buddy* ptr = aPersonsList.getBuddyAt(3);

	aPersonsList.removePerson("Maj Moln", "city", 154.0f);
	if (aPersonsList.getCurrentNrOfPersons() != 3)
	{
		cout << "NOT CORRECT amount of buddies, expected 3 " << endl;
		return false;
	}

	aPersonsList.removePerson("Lisa Land", "city", 167.5f);
	if (aPersonsList.getCurrentNrOfPersons() != 2)
	{
		cout << "NOT CORRECT amount of buddies, expected 2 " << endl;
		return false;
	}

	aPersonsList.removePerson("Svenne Snoe", "city", 161.0f);
	if (aPersonsList.getCurrentNrOfPersons() != 1)
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
	PersonsList bb1;
	PersonsList bb2(bb1);

	if (bb1.getCurrentNrOfPersons() != 0)
	{
		cout << "NOT CORRECT amount of buddies" << endl;
		return false;
	}

	bb1.addPerson("Lisa Land", "city", 167.5f);
	bb1.addPerson("Maj Moln", "city", 154.0f);
	bb1.addPerson("Ralle Regn", "city", 199.5f);

	PersonsList bb3 = bb1;
	if (bb3.getCurrentNrOfPersons() != 3)
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