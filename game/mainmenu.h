#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>

#include <common/scene.h>

class MainMenu : public Scene
{
	public:
		MainMenu();
		virtual ~MainMenu();

		void MainMenu::update(float deltaTime);

	private:

};

#endif /* MAINMENU_H */ 
