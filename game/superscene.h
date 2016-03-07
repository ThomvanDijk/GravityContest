#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include <iostream>

#include <common/scene.h>
#include <common/sprite.h>

class SuperScene: public Scene 
{
	public:
		SuperScene();
		virtual ~SuperScene();

	private:
		Sprite* sprite;

};

#endif /* SUPERSCENE_H */ 
