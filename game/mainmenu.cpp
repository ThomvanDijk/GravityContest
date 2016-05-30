#include "mainmenu.h"

using namespace std;

MainMenu::MainMenu() : Scene()
{
	titleText = new Text();
	addChild(titleText);
}

MainMenu::~MainMenu()
{
	
}

void MainMenu::update(float deltaTime)
{
	// Goto next scene with ">" i.e. "." button.
	if (input()->getKeyDown('.')) {
		setActiveScene(1);
	}
}
