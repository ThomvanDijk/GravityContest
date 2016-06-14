#include "mainmenu.h"

using namespace std;

MainMenu::MainMenu() : Scene()
{
	//titleText = new Text("abcdefghijklmnopqrstuvwxyz");
	titleText = new Text("Gravity Fighters");
	titleText->position = Point(50, 100);
	
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
