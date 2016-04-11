#include "gamescene.h"

using namespace std;

GameScene::GameScene() : Scene()
{
	cout << "new scene created" << endl;
	
	entity = new Entity();
	entity2 = new Entity();
	
	entity->position = Point(400, 400);
	entity2->position = Point(200, 200);
	
	addChild(entity);
	addChild(entity2);
}

GameScene::~GameScene()
{
	
}

void GameScene::update(float deltaTime)
{
	if (input()->getKey(GLFW_KEY_SPACE)) {
		entity2->rotation += 0.1 * deltaTime;
	}
	
	entity->rotation -= 0.1 * deltaTime;
}
