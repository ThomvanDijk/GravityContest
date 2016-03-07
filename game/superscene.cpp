#include "superscene.h"

using namespace std;

SuperScene::SuperScene() : Scene() 
{
	cout << "new scene created" << endl;
	
	sprite = new Sprite();
}

SuperScene::~SuperScene() 
{
	delete sprite;
}
