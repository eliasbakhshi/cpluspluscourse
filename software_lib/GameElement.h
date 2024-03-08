#pragma once
#include "Headers.h"

class GameElement {
public:
	string name = "";
	GameElement();
	string createEvent(string condition, string theEvent);
	string	listAffectedEvents(string condition);
	string	triggerEvents(string condition);
	string	clearEvent(string condition);
};
