#include "gamescene.h"

using namespace std;

GameScene::GameScene() : Scene()
{
	cout << "new scene created" << endl;

	fighter1 = new Fighter();
	//fighter1->location = Point(400, 500);
	addChild(fighter1);
}

GameScene::~GameScene()
{
	
}

void GameScene::update(float deltaTime)
{
	fighter1->update(deltaTime);

	if (input()->getKey(GLFW_KEY_SPACE)) {
		fighter1->accelerate = true;
	}
	if (input()->getKey(GLFW_KEY_LEFT)) {
		fighter1->rotateLeft();
	}
	if (input()->getKey(GLFW_KEY_RIGHT)) {
		fighter1->rotateRight();
	}
}
