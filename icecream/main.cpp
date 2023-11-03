#include <iostream>
#include <string>

using namespace std;


int main() {
	int totalAmount = 0, scoreRound = 0;
	string icecreams[10], theInput;
	float icecreamsScores[] = { 0,0,0,0,0,0,0,0,0,0 };
	bool moreScore = true;


	cout << "How many ice creams will be judged (max 10)? ";
	getline(cin, theInput);
	totalAmount = stoi(theInput);

	// exit the app if the amount is more that 10
	if (totalAmount > 10) {
		cout << "\n---> Program stops because you wrote a number more than 10.\n\n";
		return 0;
	}
	int test = sizeof(icecreams) / sizeof(icecreams[0]);

	// Get the icecreams names
	for (int i = 0; i < totalAmount; i++) {
		getline(cin, icecreams[i]);
	}

	// Get the score for each icecream.
	while (moreScore) {
		for (int i = 0; i < totalAmount; i++) {
			cout << icecreams[i] << ": ";
			getline(cin, theInput);
			icecreamsScores[i] += stof(theInput);
		}
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

	int maxIndex = distance(icecreamsScores, max_element(icecreamsScores, icecreamsScores + totalAmount));
	int minIndex = distance(icecreamsScores, min_element(icecreamsScores, icecreamsScores + totalAmount));
	cout << "\n\n";
	cout << "The ice cream with highest grade is " << icecreams[maxIndex] << " which has score " << icecreamsScores[maxIndex] / scoreRound << endl;
	cout << "The ice cream with lowest grade is " << icecreams[minIndex] << " which has score " << icecreamsScores[minIndex] / scoreRound << endl << endl << endl;
	cout << "\n\n";

	// Get a iceream name and check if it is in the list or not.
	cout << "Input the name of your favorite ice cream: ";
	getline(cin, theInput);
	bool valueFound = false;
	for (int i = 0; i < totalAmount; i++) {
		if (icecreams[i] == theInput) {
			valueFound = true;
			break;
		}
	}
	cout << "\n";
	valueFound ? cout << theInput << " has been graded. \n" : cout << "Sorry, " << theInput << " has not been graded this time.\n";


	return 0;
}
