#include "pch.h"
#include "EventManager.h"

void EventManager::createEvent(string EventCondition, string Event) {
    if (Event != "" && EventCondition != "") {
        cout << "Event " << Event << " created with the condition " << EventCondition << endl;
    }
}

string EventManager::listAffectedEvents(string EventCondition) {
    return "None yet!";
}

void EventManager::triggerEvents(string EventCondition) {
    if (EventCondition != "") {
        cout << "Event triggered!" << endl;
    }
}

void EventManager::clearEvent(string Event) {
    if (Event != "") {
        cout << "Event cleared successfully!" << endl;
    }
}
