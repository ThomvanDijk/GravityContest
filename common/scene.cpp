#include <common/scene.h>

Scene::Scene() : Entity()
{
	
}

Scene::~Scene()
{
	
}

void Scene::updateScene()
{
	// update() all Children (recursively)
	std::vector<Entity*> children = this->getChildren();
	std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		this->updateScene();
	}
}
