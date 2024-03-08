#pragma once
#include "Headers.h"
#include "GameElement.h"

class Scene : public GameElement {
public:
	string listAvailableElements();
	bool isAvailable(string GameElementName);
	bool isGameObject(string GameElementName);
};
