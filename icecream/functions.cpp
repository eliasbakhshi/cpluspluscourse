#pragma once
#include "headers.h"

MI mi;

// Get the icecreams names
void getNames(string tempArr[], int array_length) {
	for (int i = 0; i < array_length; i++) {
		system("cls");
		cout << to_string(i + 1) + "th Icecream's name: ";
		getline(cin, tempArr[i]);
	}
}

// Get the score for each icecream.
void getScores(string icecreams[], float icecreamsScores[], int totalAmount) {
	string theInput;
	for (int i = 0; i < totalAmount; i++) {
		system("cls");
		icecreamsScores[i] += mi.get_float("Score for " + icecreams[i] + ": ");
	}
}