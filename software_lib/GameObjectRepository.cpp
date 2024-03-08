#include "pch.h"
#include "GameObjectRepository.h"

GameObjectRepository::GameObjectRepository() {
}

GameObject GameObjectRepository::getGameObject(string gameElementName) {
    GameObject bruh;
    return bruh;
}

void GameObjectRepository::addToVector(GameObject name) {
    GameObject* ptr = new GameObject;
    objects.push_back(ptr);
}
