#ifndef INTROSCREEN_H
#define INTROSCREEN_H

#include <iostream>

#include <common/scene.h>

class IntroScreen : public Scene
{
	public:
		IntroScreen();
		virtual ~IntroScreen();

		void IntroScreen::update(float deltaTime);

	private:


};

#endif /* INTROSCREEN_H */ 
