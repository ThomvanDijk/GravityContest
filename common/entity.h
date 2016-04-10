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

		// transform
		Point position; /**< @brief The position of the Entity */
		float rotation; /**< @brief The rotation of the Entity */
		Point scale; /**< @brief The scale of the Entity */

	private:
		Line* _line;

};

#endif /* ENTITY_H */
