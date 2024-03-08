#include "pch.h"
#include "Game.h"

GameObject Game::selectGameObject(string name) {	
	return this->myGameObjects.getGameObject(name);
}

bool Game::addGameObject(string name) {
	return this->myGameObjects.addToVector(name);
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
