#include "pch.h"
#include "../software_lib/Game.h"
#include "../software_lib/GameObjectRepository.h"
#include "../software_lib/GameObject.h"


TEST(Game_class, addGameObject_and_selectGameObject) {
	Game game;
	string objectName = "chair";
	game.addGameObject(objectName);
	GameObject gameObject(objectName);

	EXPECT_EQ(gameObject.name, game.selectGameObject(objectName).name);

	objectName = "car";
	game.addGameObject(objectName);
	GameObject gameObject2(objectName);

	EXPECT_EQ(gameObject2.name, game.selectGameObject(objectName).name);
}

TEST(GameObject_class, listInteractionTypes) {
	GameObject gameObject("");

	EXPECT_STREQ("1) Grab\n2) Sit on\n3) Stand on\n", gameObject.listInteractionTypes().c_str());
}
//
//TEST(GameObject_class, startInteraction) {
//	GameObject gameObject;
//
//	EXPECT_STREQ("Interaction started successfully!", gameObject.startInteraction().c_str());
//}
//
//TEST(GameObject_class, listCurrentInteractionOptions) {
//	GameObject gameObject;
//
//	EXPECT_STREQ("No specific options found for this particular object!\n", gameObject.listCurrentInteractionOptions().c_str());
//}
//
//TEST(GameObject_class, setCurrentInteractionOptions) {
//	GameObject gameObject;
//
//	EXPECT_STREQ("The specific option you have chosen is: Sit on", gameObject.setCurrentInteractionOptions(1).c_str());
//}
//
//TEST(GameObject_class, startCurrentInteraction) {
//	GameObject gameObject;
//
//	EXPECT_STREQ("Current interaction started!", gameObject.startCurrentInteraction().c_str());
//}
//
//TEST(GameObject_class, abortCurrentInteraction) {
//	GameObject gameObject;
//
//	EXPECT_STREQ("Interaction aborted!", gameObject.abortCurrentInteraction().c_str());
//}
//
//
//
//TEST(Game_class, selectGameObject) {
//	GameObject gameObject;
//
//	EXPECT_STREQ("Object created: ", gameObject.selectGameObject().c_str());
//}
//
//TEST(Game_class, selectInteraction) {
//	GameObject gameObject;
//
//	EXPECT_STREQ("Interaction aborted!", gameObject.selectInteraction().c_str());
//}
//
TEST(Game_class, setInteractionOptions) {
	Game game;
	GameObject gameObject("");
	EXPECT_STREQ("The specific option you have chosen is: Grab" , game.setInteractionOptions(gameObject, 0).c_str());
}
//
TEST(Game_class, startInteraction) {
	Game game;
	GameObject gameObject("");

	EXPECT_STREQ("Interaction started successfully!", game.startInteraction(gameObject).c_str());
}

TEST(Game_class, abortInteraction) {
	Game game;
	GameObject gameObject("");

	EXPECT_STREQ("Interaction aborted!", game.abortInteraction(gameObject).c_str());
}
