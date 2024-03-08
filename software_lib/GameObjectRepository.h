#pragma once
#include "GameObject.h"
#include "Game.h"

class GameObjectRepository {
public:
	vector<GameObject*> objects;
	GameObjectRepository();
	GameObject getGameObject(string gameElementName);
	void addToVector(GameObject name);
};