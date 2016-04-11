#include "superscene.h"

using namespace std;

SuperScene::SuperScene() : Scene() 
{
	cout << "new scene created" << endl;
	
	entity = new Entity();
	entity2 = new Entity();
	
	entity->position = Point(400, 400);
	entity2->position = Point(40, 60);
	
	addChild(entity);
	addChild(entity2);
}

SuperScene::~SuperScene() 
{
	
}

void SuperScene::update()
{
	entity->rotation -= 0.01;
}
