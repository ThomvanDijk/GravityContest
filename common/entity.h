#ifndef ENTITY_H
#define ENTITY_H

#include <common/line.h>
#include <common/point.h>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		Line* line() { return _line; };
		Point position;

	private:
		Line* _line;

};

#endif /* ENTITY_H */
