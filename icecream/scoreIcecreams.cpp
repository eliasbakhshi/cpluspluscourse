#include "headers.h"

/* Score the icecreams. */
void scoreIcecreams() {
	// initialization of the variables
	string* icecreams = nullptr, * icecreamsList = nullptr;
	float* icecreamsScores = nullptr;
	int totalAmount = 0, scoreRound = 0;
	string theInput, filename = "db.txt";
	bool moreScore = true;
	MI mi;
	MF mf;
	

	totalAmount = mi.get_int("How many ice creams will be judged? ");
	
	icecreams = new string[totalAmount];
	icecreamsScores = new float[totalAmount] {0.0};

	// Get the icecreams names
	getNames(icecreams, totalAmount);

	// Get the score for each icecream.
	while (moreScore) {
		getScores(icecreams, icecreamsScores, totalAmount);
		scoreRound++;
		theInput = mi.get_string("More gradings (y/n)? ");
		moreScore = theInput == "y" || theInput == "yes" ? true : false;
	}

	// Show the reault
	system("cls");
	cout << "The number of gradings is " << scoreRound << endl;
	cout << "The average score for each ice cream is\n\n";

	for (int i = 0; i < totalAmount; i++) {
		cout << icecreams[i] << " : " << icecreamsScores[i] / scoreRound << endl;
	}

	__int64 maxIndex = distance(icecreamsScores, max_element(icecreamsScores, icecreamsScores + totalAmount));
	__int64 minIndex = distance(icecreamsScores, min_element(icecreamsScores, icecreamsScores + totalAmount));
	cout << "\n\n";
	cout << "The ice cream with highest grade is " << icecreams[maxIndex] << " which has score " << icecreamsScores[maxIndex] / scoreRound << endl;
	cout << "The ice cream with lowest grade is " << icecreams[minIndex] << " which has score " << icecreamsScores[minIndex] / scoreRound << endl << endl << endl;
	cout << "\n";

	// Get a iceream name and check if it is in the list or not.
	theInput = mi.get_string("Input the name of your favorite ice cream: ", true);
	if (!theInput.empty()) {
		bool valueFound = false;
		for (int i = 0; i < totalAmount; i++) {
			if (icecreams[i] == theInput) {
				valueFound = true;
				break;
			}
		}
		valueFound ? cout << theInput << " has been graded. \n\n" : cout << "Sorry, " << theInput << " has not been graded this time.\n\n";
	} else cout << "Du skrev inget :) \n\n" << endl;

	theInput = mi.get_string("Do you want to save the new list in the file? (y/n) ");
	if (theInput == "y") {
		if (mf.saveToFile(filename, icecreams, icecreamsScores, totalAmount)) {
			cout << "Information have been saved in the " << filename << ". \n\n";
		} else cout << "Failed to save in the file. \n\n";
	}

	delete[] icecreams;
	delete[] icecreamsScores;
	delete[] icecreamsList;
}