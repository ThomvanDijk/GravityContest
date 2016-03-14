#ifndef ENTITY_H
#define ENTITY_H

#include <common/sprite.h>
#include <common/point.h>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		Sprite* sprite() { return _sprite; };
		Point* position;

	private:
		Sprite* _sprite;

};

#endif /* ENTITY_H */
