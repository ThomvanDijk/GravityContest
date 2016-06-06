#ifndef ENTITY_H
#define ENTITY_H

#include <common/line.h>
#include <common/point.h>

#include <iostream>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		std::vector<Line*> getLineList() { return _lineList; };
		void Entity::addLine(Line* line);

		void addChild(Entity* child);
		void Entity::removeChild(Entity* child);

		// transform
		Point position; /**< @brief The position of the Entity */
		float rotation; /**< @brief The rotation of the Entity */
		Point scale; /**< @brief The scale of the Entity */

	private:
		int _guid;
		static int _nextGuid;

		std::vector<Line*> _lineList;

		Entity* _parent;
		std::vector<Entity*> _children;

};

#endif /* ENTITY_H */
