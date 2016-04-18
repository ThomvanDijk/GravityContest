#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>

#include <common/entity.h>
#include <common/input.h>
#include <common/vector2.h>

class Fighter : public Entity
{
	public:
		Fighter();
		virtual ~Fighter();

		void Fighter::update(float deltaTime);

	private:
		Vector2* location;
		
};

#endif /* FIGHTER_H */ 
