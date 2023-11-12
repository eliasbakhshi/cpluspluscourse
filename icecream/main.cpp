#include "functions.h"


int main() {
	// initialization of the variables
	bool running = true;
	string theInput;

	while (running) {
		cout << "<-- Here is the list --> " << endl;
		cout << "1: Show the icecreams." << endl;
		cout << "2: Score the icecreams." << endl << endl;

		cout << "exit(e): Exit the game." << endl;

		cout << endl << "Please enter your choice: ";
		cin >> theInput;

		if (theInput == "1") {
			showScore();
		} else if (theInput == "2") {
			scoreIcecreams();
		} else if (theInput == "exit" || theInput == "e") {

		}
	}	

	return 0;
}
