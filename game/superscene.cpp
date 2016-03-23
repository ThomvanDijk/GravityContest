#include "superscene.h"

using namespace std;

SuperScene::SuperScene() : Scene() 
{
	cout << "new scene created" << endl;
	
	entity = new Entity();
	entity2 = new Entity();
	
	entity2->position = Point(200, 200);
	
	addChild(entity);
	addChild(entity2);
}

SuperScene::~SuperScene() 
{
	
}
