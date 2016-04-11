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

// Include superscene for all scenes
#include "gamescene.h"

int main(void)
{
	// instantiate core
	Core core;

	// Create here the scenes, in this case I create a superscene but that isn't allowed later.
	GameScene* gameScene = new GameScene();

	// Do this until the ESC key is pressed or the window is closed
	while (core.running)
	{
		core.update(gameScene); // update and render the current scene
	}

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
