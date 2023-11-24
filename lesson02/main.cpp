#include "header.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	BuddyBook bb;

	bb.addBuddy("Adam", 149, 200.0f);
	bb.addBuddy("Jens", 22, 176.9f);
	bb.addBuddy("Goran", 51, 175.5f);
	bb.addBuddy("Pelle", 12, 44.2f);

	bb.showBuddies();

	cout << "\n";
	bb.removeBuddy("Jens", 22, 176.9f);
	cout << "\n";

	bb.showBuddies();

	cout << "\n";

	BuddyBook bb2(bb);

	cout << "<---" << endl;

	bb2.showBuddies();

	cout << "\n";

	BuddyBook bb3;
	bb3.addBuddy("Flappe", 2, 23.5f);

	bb3 = bb;

	bb3.showBuddies();

	return 0;
}