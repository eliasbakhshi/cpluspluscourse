#include "Headers.h"
#include "../software_lib/Game.h"
#include "../software_lib/GameObjectRepository.h"
#include "../software_lib/GameObject.h"

int main() {

	Game game;
	string object, theInput, res = "";
	vector<string> objects{ "chair", "car" };

	for (size_t i = 0; i < objects.size(); i++) {
		cout << i + 1 << ": " << objects[i] << endl;
	}

	cout << "Choose object: ";
	getline(cin, object);
	game.addGameObject(objects[stoi(object)-1]);
	GameObject gameObject = game.selectGameObject(objects[stoi(object) - 1]);
	cout << gameObject.listInteractionTypes() << endl;
	cout << "Choose option: ";
	getline(cin, theInput);
	res = game.setInteractionOptions(gameObject, stoi(theInput) - 1);
	cout << res << endl;
	cout << game.startInteraction(gameObject) << endl;

	cout << "Press Enter to abort interaction..." << endl;
	getchar();

	cout << game.abortInteraction(gameObject);

	//return 0;

}