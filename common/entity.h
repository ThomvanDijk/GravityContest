#ifndef ENTITY_H
#define ENTITY_H

#include <common/sprite.h>
#include <common/line.h>
#include <common/point.h>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		Sprite* sprite() { return _sprite; };
		Line* line() { return _line; };
		Point position;

	private:
		Sprite* _sprite;
		Line* _line;

};

#endif /* ENTITY_H */
