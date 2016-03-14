#include <common/core.h>

Core::Core()
{
	running = true;
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

	// if esc key is pressed
	if (glfwGetKey(_renderer.window(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		running = false;
	}
	
	// if close button is pressed
	if (glfwWindowShouldClose(_renderer.window()) != 0) {
		running = false;
	}
}
