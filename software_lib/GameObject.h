#pragma once
#include "Headers.h"
#include "GameElement.h"

class GameObject : public GameElement {
	vector<string> intractiontypes{ "Grab", "Sit on", "Stand on" };
public:
	GameObject(string name);
	string listInteractionTypes();
	string startInteraction();
	string listCurrentInteractionOptions();
	string setCurrentInteractionOptions(int theOption);
	string startCurrentInteraction();
	string abortCurrentInteraction();
};