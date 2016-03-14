#include "superscene.h"

using namespace std;

SuperScene::SuperScene() : Scene() 
{
	cout << "new scene created" << endl;
	
	entity = new Entity();
	entity2 = new Entity();
	
	entity2->position = new Point(0, 0);
	//addChild(entity);
}

SuperScene::~SuperScene() 
{
	
}
