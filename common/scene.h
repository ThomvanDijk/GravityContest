#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <common/entity.h>

class Scene: public Entity
{
	public:
		Scene();
		virtual ~Scene();

		void updateScene();

		// the extending class must implement the update function
		virtual void update() = 0;

		// child
		void addChild(Entity* child);
		std::vector<Entity*> getChildList() { return _childList; };

	private:
		std::vector<Entity*> _childList;
};

#endif /* SCENE_H */
