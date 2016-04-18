#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include <iostream>

#include <common/scene.h>

class VictoryScreen : public Scene
{
	public:
		VictoryScreen();
		virtual ~VictoryScreen();

		void VictoryScreen::update(float deltaTime);

	private:


};

#endif /* VICTORYSCREEN_H */ 
