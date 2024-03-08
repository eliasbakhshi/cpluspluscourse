#include "pch.h"
#include "../software_lib/Game.h"
#include "../software_lib/GameObjectRepository.h"
#include "../software_lib/GameObject.h"


TEST(Unit_testing, selectGameObject) {
	Game game;

	string object = "chair";
	EXPECT_STREQ("Object created: chair", game.selectGameObject(object).c_str());

	string object = "car";
	EXPECT_STREQ("Object created: car", game.selectGameObject(object).c_str());
}

TEST(Unit_testing, listInteractionTypes) {
	GameObject gameObject;

	EXPECT_STREQ("1) Grab\n2) Sit on\n3) Stand on\n", gameObject.listInteractionTypes().c_str());
}

TEST(Unit_testing, selectInteraction) {
	GameObject gameObject;

	//EXPECT_STREQ("1) Grab\n2) Sit on\n3) Stand on\n", gameObject.selectInteraction().c_str());
}

TEST(Unit_testing, startInteraction) {
	GameObject gameObject;

	//EXPECT_STREQ("1) Grab\n2) Sit on\n3) Stand on\n", gameObject.selectInteraction().c_str());
}

TEST(Unit_testing, abortInteraction) {
	GameObject gameObject;

	//EXPECT_STREQ("1) Grab\n2) Sit on\n3) Stand on\n", gameObject.selectInteraction().c_str());
}