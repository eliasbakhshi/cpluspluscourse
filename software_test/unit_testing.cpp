#include "pch.h"
#include "../software_lib/Game.h"
#include "../software_lib/GameObjectRepository.h"
#include "../software_lib/GameObject.h"


TEST(GameObject_class, selectGameObject) {
	Game game;

	string object = "chair";
	EXPECT_STREQ("Object created: chair", game.selectGameObject(object).c_str());

	object = "car";
	EXPECT_STREQ("Object created: car", game.selectGameObject(object).c_str());
}

TEST(GameObject_class, listInteractionTypes) {
	GameObject gameObject;

	EXPECT_STREQ("1) Grab\n2) Sit on\n3) Stand on\n", gameObject.listInteractionTypes().c_str());
}

TEST(GameObject_class, startInteraction) {
	GameObject gameObject;

	EXPECT_STREQ("Interaction started successfully!", gameObject.startInteraction().c_str());
}

TEST(GameObject_class, listCurrentInteractionOptions) {
	GameObject gameObject;

	EXPECT_STREQ("No specific options found for this particular object!\n", gameObject.listCurrentInteractionOptions().c_str());
}

TEST(GameObject_class, setCurrentInteractionOptions) {
	GameObject gameObject;

	EXPECT_STREQ("The specific option you have chosen is: Sit on", gameObject.setCurrentInteractionOptions(1).c_str());
}

TEST(GameObject_class, startCurrentInteraction) {
	GameObject gameObject;

	EXPECT_STREQ("Current interaction started!", gameObject.startCurrentInteraction().c_str());
}

TEST(GameObject_class, abortCurrentInteraction) {
	GameObject gameObject;

	EXPECT_STREQ("Interaction aborted!", gameObject.abortCurrentInteraction().c_str());
}

