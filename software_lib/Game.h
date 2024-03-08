#pragma once
#include "Headers.h"
#include "GameObjectRepository.h"
#include "Scene.h"
#include "GameObject.h"


class Game {
public:
	Scene currentScene;
	vector<Scene> playerInventory;

	string selectGameObject(string name);
	string selectInteraction(GameObject theGameObject, int theInteraction);
	string setInteractionOptions(GameObject gameobj, int theOption);
	string startInteraction(GameObject gameobj);
	string abortInteraction(GameObject gameObject);
};