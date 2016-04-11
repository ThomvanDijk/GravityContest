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
	// update the _deltaTime
	_calculateDeltaTime();

	// Update input instance in Scene
	scene->input()->updateInput(_renderer.window());

	// Update Scene (and recursively all children)
	scene->updateScene((float) _deltaTime);

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

// calcuate the _deltaTime
double Core::_calculateDeltaTime()
{
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();
	_deltaTime = startTime - lastTime;
	lastTime = startTime;

	return _deltaTime;
}
