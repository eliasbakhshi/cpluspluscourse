#include "pch.h"
#include "GameObjectRepository.h"

GameObjectRepository::GameObjectRepository() {}

GameObject GameObjectRepository::getGameObject(string gameElementName) {
	GameObject objectGame("");
	for (size_t i = 0; i < this->objects.size(); i++) {
		if ((*this->objects[i]).name == gameElementName) {
			objectGame = *this->objects[i];
		}
	}
	return objectGame;
}

bool GameObjectRepository::addToVector(string gameElementName) {
	GameObject* ptr = new GameObject(gameElementName);
	this->objects.push_back(ptr);
	return true;
}
