#include <common/scene.h>

Scene::Scene() : Entity()
{
	
}

Scene::~Scene()
{
	
}

void Scene::updateScene()
{
	int size = _childList.size();
	for (int i = 0; i < size; i++) {
		
	}
}

void Scene::addChild(Entity* child)
{
	_childList.push_back(child);
}
