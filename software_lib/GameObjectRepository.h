#pragma once
#include "GameObject.h"

class GameObjectRepository {
	vector<GameObject*> objects;
public:
	GameObjectRepository();
	GameObject getGameObject(string gameElementName);
	bool addToVector(string gameElementName);
};