#include <common/scene.h>

Scene::Scene() : Entity()
{
	// scene has an input
	_input = new Input();
}

Scene::~Scene()
{
	
}

void Scene::updateScene(float deltaTime)
{
	this->update(deltaTime);

	int size = _childList.size();
	for (int i = 0; i < size; i++) {
		// nm
	}
}

void Scene::addChild(Entity* child)
{
	_childList.push_back(child);
}
