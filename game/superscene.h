#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include <iostream>

#include <common/scene.h>

class SuperScene: public Scene 
{
	public:
		SuperScene();
		virtual ~SuperScene();

		void SuperScene::update(float deltaTime);

	private:
		Entity* entity;
		Entity* entity2;

};

#endif /* SUPERSCENE_H */ 
