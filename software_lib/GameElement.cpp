#include "pch.h"
#include "GameElement.h"



GameElement::GameElement() {
}

string GameElement::createEvent(string condition, string theEvent) {
    return "createEvent is called.";
}
 
string GameElement::listAffectedEvents(string condition) {
    return "listAffectedEvents is called.";
}

string GameElement::triggerEvents(string condition) {
    return "triggerEvents is called.";
}

string GameElement::clearEvent(string condition) {
    return "clearEvent is called.";
}
