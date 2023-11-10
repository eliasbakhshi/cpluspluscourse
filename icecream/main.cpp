#include "functions.h"


int main() {
	string* icecreams = nullptr;
	float* icecreamsScores = nullptr;
	int totalAmount = 0, scoreRound = 0;
	string theInput, fileInput;
	bool moreScore = true;
	string* icecreamsList = readFile();
	cout << "vvvvvv " << * icecreamsList << endl;
	cout << "test2" << endl;
	cout << "How many ice creams will be judged? ";
	getline(cin, theInput);
	totalAmount = stoi(theInput);
	icecreams = new string[totalAmount];
	icecreamsScores = new float[totalAmount] {0.0};
	for (size_t i = 0; i < sizeof(icecreamsList) / sizeof(icecreamsList[0]); i++) {
		cout << "arr " << icecreamsList[i] << endl;
	}

	int test = sizeof(*icecreams) / sizeof(string);
	cout << test << endl;

	// Get the icecreams names
	getNames(icecreams, totalAmount);

	// Get the score for each icecream.
	while (moreScore) {
		getScores(icecreams, icecreamsScores, totalAmount);
		scoreRound++;
		cout << "More gradings (y/n)? ";
		getline(cin, theInput);
		moreScore = theInput == "y" ? true : false;
	}

	// Show the reault
	cout << "\n\nThe number of gradings is " << scoreRound << endl;
	cout << "The average score for each ice cream is\n\n";

	for (int i = 0; i < totalAmount; i++) {
		cout << icecreams[i] << " : " << icecreamsScores[i] / scoreRound << endl;
	}

	__int64 maxIndex = distance(icecreamsScores, max_element(icecreamsScores, icecreamsScores + totalAmount));
	__int64 minIndex = distance(icecreamsScores, min_element(icecreamsScores, icecreamsScores + totalAmount));
	cout << "\n\n";
	cout << "The ice cream with highest grade is " << icecreams[maxIndex] << " which has score " << icecreamsScores[maxIndex] / scoreRound << endl;
	cout << "The ice cream with lowest grade is " << icecreams[minIndex] << " which has score " << icecreamsScores[minIndex] / scoreRound << endl << endl << endl;
	cout << "\n\n";

	// Get a iceream name and check if it is in the list or not.
	cout << "Input the name of your favorite ice cream: ";
	getline(cin, theInput);
	if (!theInput.empty()) {
		bool valueFound = false;
		for (int i = 0; i < totalAmount; i++) {
			if (icecreams[i] == theInput) {
				valueFound = true;
				break;
			}
		}
		cout << "\n";
		valueFound ? cout << theInput << " has been graded. \n" : cout << "Sorry, " << theInput << " has not been graded this time.\n";
	} else cout << "Du skrev inget :) " << endl;

	delete[] icecreams;
	delete[] icecreamsScores;
	delete[] icecreamsList;

	return 0;
}
