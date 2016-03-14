#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include <common/sprite.h>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		// child
		void addChild(Entity* child);
		void removeChild(Entity* child);

		Entity* getChild(unsigned int i);

		const std::vector<Entity*>& getChildren() { return _children; };

		// sprite
		Sprite* sprite() { return _sprite; };

	private:
		int _guid;
		static int _nextGuid;

		Entity* _parent;
		std::vector<Entity*> _children;

		Sprite* _sprite;

};

#endif /* ENTITY_H */
