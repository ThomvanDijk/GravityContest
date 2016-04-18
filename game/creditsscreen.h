#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#include <iostream>

#include <common/scene.h>

class CreditsScreen : public Scene
{
	public:
		CreditsScreen();
		virtual ~CreditsScreen();

		void CreditsScreen::update(float deltaTime);

	private:
	

};

#endif /* CREDITSSCREEN_H */ 
