#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <iostream>

#include <common/scene.h>
#include "fighter.h"

class GameScene : public Scene
{
	public:
		GameScene();
		virtual ~GameScene();

		void GameScene::update(float deltaTime);

	private:
		Entity* entity;
		Entity* entity2;

		Fighter* fighter1;

};

#endif /* GAMESCENE_H */ 
