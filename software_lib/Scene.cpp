#include "pch.h"
#include "Scene.h"

string Scene::listAvailableElements() {
    return "1) Element 1\n2) Element 2\n3) Element 3\n";
}

bool Scene::isAvailable(string GameElementName) {
    bool av;
    if (GameElementName != "Element 1" || GameElementName != "Element 2" || GameElementName != "Element 3") {
        av = false;
    }
    else {
        av = true;
    }
    return av;
}

bool Scene::isGameObject(string GameElementName) {
    if (GameElementName != "object" || GameElementName != "ptr") {
        return false;
    }
    else {
        return true;
    }
}
