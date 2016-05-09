#ifndef ENTITY_H
#define ENTITY_H

#include <common/line.h>
#include <common/point.h>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		std::vector<Line*> getLineList() { return lineList; };
		void Entity::addLine(Line* line);

		// transform
		Point position; /**< @brief The position of the Entity */
		float rotation; /**< @brief The rotation of the Entity */
		Point scale; /**< @brief The scale of the Entity */

	private:
		std::vector<Line*> lineList;

};

#endif /* ENTITY_H */
