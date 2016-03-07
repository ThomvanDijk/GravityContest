#include <common/core.h>

Core::Core()
{
	
}

Core::~Core()
{
	
}

void Core::update(Scene* scene)
{
	// Update Scene (and recursively all children)
	scene->updateScene();

	// Render Scene
	_renderer.renderScene(scene);
}