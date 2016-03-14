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

		// child
		void addChild(Entity* child);
		std::vector<Entity*> getChildList() { return _childList; };

	private:
		std::vector<Entity*> _childList;
};

#endif /* SCENE_H */
