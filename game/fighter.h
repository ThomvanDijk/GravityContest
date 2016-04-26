#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>

#include <common/entity.h>
#include <common/vector2.h>

class Fighter : public Entity
{
	public:
		Fighter();
		virtual ~Fighter();

		void Fighter::update(float deltaTime);

		void Fighter::rotateLeft();
		void Fighter::rotateRight();

		bool accelerate;

	private:
		Vector2* vector2;

		Vector2 location;
		Vector2 velocity;
		Vector2 acceleration;
		Vector2 mouse;
		Vector2 direction;
		Vector2 force;
		Vector2 gravity;

		float topspeed;
		float angle;
		float deltaTime;
		
};

#endif /* FIGHTER_H */ 
