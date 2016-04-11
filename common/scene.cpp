#include <common/scene.h>

Scene::Scene() : Entity()
{
	
}

Scene::~Scene()
{
	
}

void Scene::updateScene()
{
	this->update();

	int size = _childList.size();
	for (int i = 0; i < size; i++) {
		// nm
	}
}

void Scene::addChild(Entity* child)
{
	_childList.push_back(child);
}
