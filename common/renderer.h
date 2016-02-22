#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/sprite.h>
#include <common/shader.h>
#include <common/texture.h>
#include <common/camera.h>

class Renderer 
{
	public:
		Renderer();
		virtual ~Renderer();

		void renderSprite(Sprite* sprite);
		GLFWwindow* window() { return _window; };

	private:
		int init();

		GLFWwindow* _window;
		int window_width;
		int window_height;

		std::string fragment_shader;
		std::string vertex_shader;

		GLuint programID;
		GLuint vertexPosition_modelspaceID;
		GLuint vertexUVID;
		GLuint matrixID;
		GLuint textureID;

		glm::mat4 ProjectionMatrix;
};

#endif /* RENDERER_H */