#include "Headers.h"
#include "../software_lib/Game.h"
#include "../software_lib/GameObjectRepository.h"
#include "../software_lib/GameObject.h"

int main() {

	Game game;
	GameObject gameObject;
	string object;
	string theOptions;

	vector<string> objects{ "chair", "car" };

	for (size_t i = 0; i < objects.size(); i++) {
		cout << i + 1 << ": " << objects[i] << endl;
	}

	cout << "Choose object: ";
	getline(cin, object);

	string res = game.selectGameObject(objects[stoi(object) - 1]);
	cout << res << endl;
	cout << gameObject.listInteractionTypes();
	cout << "Choose option: ";
	getline(cin, theOptions);
	res = game.selectInteraction(gameObject, stoi(theOptions) - 1);
	cout << res << endl;
	cout << game.startInteraction(gameObject) << endl;

	cout << "Press Enter to abort interaction..." << endl;
	getchar();

	cout << game.abortInteraction(gameObject);

}