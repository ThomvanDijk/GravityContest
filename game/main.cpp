// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/sprite.h>

int main(void)
{
	Renderer renderer;
	Sprite* sprite = new Sprite();

	// Do this until the ESC key is pressed or the window is closed
	while (glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0)
	{
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		renderer.renderSprite(sprite);

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();
	} 

	delete sprite;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
