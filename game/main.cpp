// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/core.h>
#include <common/renderer.h>
//#include <common/sprite.h>

#include "superscene.h"

int main(void)
{
	// instantiate core
	Core core;

	// Create here the scenes, in this case I create a superscene but that isn't allowed later.
	SuperScene* superScene = new SuperScene();

	//Renderer renderer;

	// Do this until the ESC key is pressed or the window is closed
	while (core.running)
	{
		//renderer.renderSprite(sprite);

		// Swap buffers
		//glfwSwapBuffers(renderer.window());
		glfwPollEvents();

		core.update(superScene); // update and render the current scene
	}

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
