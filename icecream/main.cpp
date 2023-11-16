#include "headers.h"

int main() {
	// initialization of the variables
	bool running = true;
	string theInput;
	MI mi;

	while (running) {
		system("cls");
		cout << "<-- Here is the list --> " << endl << endl;
		cout << "1: Show the icecreams." << endl;
		cout << "2: Score the icecreams." << endl << endl;

		cout << "exit(e): Exit the game." << endl;

		cout << endl << "Please enter your choice: ";
		getline(cin, theInput);

		if (theInput == "exit" || theInput == "e") {
			running = false;
			break;
		} else if (theInput == "1") {
			system("cls");
			showScore();
		} else if (theInput == "2") {
			system("cls");
			scoreIcecreams();
		} else cout << "The choice is not in the menu.\n\n";

		if (running) {
			theInput = mi.get_string("Please press enter to go to the menu again", true);
		}
	}

	return 0;
}
