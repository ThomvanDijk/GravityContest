#include "superscene.h"

using namespace std;

SuperScene::SuperScene() : Scene() 
{
	cout << "new scene created" << endl;
	
	entity = new Entity();
	//addChild(entity);
}

SuperScene::~SuperScene() 
{
	
}
