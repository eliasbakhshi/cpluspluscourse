#pragma once
#include "Headers.h"
#include "GameObject.h"
#include "GameObjectRepository.h"
#include "Scene.h"


class Game {
	GameObjectRepository myGameObjects;
	Scene currentScene;
	vector<Scene> playerInventory;
public:

	GameObject selectGameObject(string name);
	bool addGameObject(string name);
	string selectInteraction(GameObject theGameObject, int theInteraction);
	string setInteractionOptions(GameObject gameobj, int theOption);
	string startInteraction(GameObject gameobj);
	string abortInteraction(GameObject gameObject);
};