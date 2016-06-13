// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include core
#include <common/core.h>

// include scene
#include "scene.h"

// include all scenes
#include "mainmenu.h"
#include "gamescene.h"

int main(void)
{
	// instantiate core
	Core core;

	// create here the scenes
	std::vector<Scene*> scenes;

	scenes.push_back(new MainMenu());
	scenes.push_back(new GameScene());

	// instantiate scene
	Scene* scene = scenes[0];

	// Do this until the ESC key is pressed or the window is closed
	while (core.running)
	{
		core.update(scenes[scene->getActiveScene()]); // update and render the current scene
	}

	// delete the scenes
	for (int i = 0; i < scenes.size(); i++) {
		delete scenes[i];
	}

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
