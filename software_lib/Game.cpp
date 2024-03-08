#include "pch.h"
#include "Game.h"

string Game::selectGameObject(string name) {
	GameObject forsure;
	return "Object created: " + name;
}

string Game::selectInteraction(GameObject theGameObject, int theInteraction) {
	return this->setInteractionOptions(theGameObject, theInteraction);
}

string Game::setInteractionOptions(GameObject gameobj, int theInteraction) {
	return gameobj.setCurrentInteractionOptions(theInteraction);
}

string Game::startInteraction(GameObject gameobj){
	return gameobj.startInteraction();
}

string Game::abortInteraction(GameObject gameObject) {
	
	return gameObject.abortCurrentInteraction();
}
