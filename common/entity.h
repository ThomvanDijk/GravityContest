#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		void addChild(Entity* child);
		void removeChild(Entity* child);

		const std::vector<Entity*>& getChildren() { return _children; };

	private:
		int _guid;
		static int _nextGuid;

		Entity* _parent;
		std::vector<Entity*> _children;
};

#endif /* ENTITY_H */
