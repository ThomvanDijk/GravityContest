#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <common/entity.h>
#include <common/input.h>

class Scene: public Entity
{
	public:
		Scene();
		virtual ~Scene();

		void updateScene(float deltaTime);

		// the extending class must implement the update function
		virtual void update(float deltaTime) = 0;

		// return input pointer
		Input* input() { return _input; };

		// child
		void addChild(Entity* child);
		std::vector<Entity*> getChildList() { return _childList; };

		void setActiveScene(int s) { _activeScene = s; }
		int getActiveScene() { return _activeScene; }

	private:
		std::vector<Entity*> _childList;

		Input* _input;

		int _activeScene;
};

#endif /* SCENE_H */
