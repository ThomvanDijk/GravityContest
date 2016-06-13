#include "mainmenu.h"

using namespace std;

MainMenu::MainMenu() : Scene()
{
	//titleText = new Text("abcdefghijklmnopqrstuvwxyz");
	titleText = new Text("space is big");
	titleText->position = Point(40, 100);
	
	addChild(titleText);
}

MainMenu::~MainMenu()
{
	delete titleText;
}

void MainMenu::update(float deltaTime)
{
	// Goto next scene with ">" i.e. "." button.
	if (input()->getKeyDown('.')) {
		setActiveScene(1);
	}
}
