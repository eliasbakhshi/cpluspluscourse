#include "pch.h"
#include "../software_lib/Game.h"
#include "../software_lib/GameObjectRepository.h"
#include "../software_lib/GameObject.h"

TEST(Main, Happy_path) {
	Game game;
	string theInput, res = "";
	vector<string> objects{ "chair", "car" };
	int object = 1;


	game.addGameObject(objects[object - 1]);
	GameObject gameObject(objects[object - 1]);
	GameObject selectedGameObject = game.selectGameObject(objects[object - 1]);

	EXPECT_EQ(gameObject.name, selectedGameObject.name);
	EXPECT_EQ("1) Grab\n2) Sit on\n3) Stand on\n", selectedGameObject.listInteractionTypes());
	EXPECT_EQ("The specific option you have chosen is: Grab", game.setInteractionOptions(selectedGameObject, 0));
	EXPECT_EQ("Interaction started successfully!", game.startInteraction(selectedGameObject));
	EXPECT_EQ("Interaction aborted!", game.abortInteraction(selectedGameObject));
}