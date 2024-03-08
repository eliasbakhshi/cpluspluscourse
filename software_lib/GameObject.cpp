#include "pch.h"
#include "GameObject.h"

GameObject::GameObject() {}

string GameObject::listInteractionTypes() {
	return "1) Grab\n2) Sit on\n3) Stand on\n";
}

string GameObject::startInteraction() {
	return "Interaction started successfully!" ;
}

string GameObject::listCurrentInteractionOptions() {
	return "No specific options found for this particular object!\n";
}

string GameObject::setCurrentInteractionOptions(int theOptions) {
	return "The specific option you have chosen is: " + intractiontypes[theOptions];
}
string GameObject::startCurrentInteraction() {
	return "Current interaction started!";
}

string GameObject::abortCurrentInteraction() {
	return "Interaction aborted!";
}
