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

#include <common/shader.h>
#include <common/line.h>
#include <common/texture.h>
#include <common/camera.h>
#include <common/scene.h>

class Renderer
{
	public:
		Renderer();
		virtual ~Renderer();

		void renderScene(Scene* scene);
		void renderEntity(glm::mat4& modelMatrix, Entity* entity);
		void renderLine(Line* line);

		int getWindowWidth() { return _window_width; }
		int getWindowHeight() { return _window_height; }

		GLFWwindow* window() { return _window; };

	private:
		int init();

		int _window_width;
		int _window_height;

		bool _fullscreen;

		inline glm::mat4 _getModelMatrix(Entity* entity);

		GLFWwindow* _window;

		std::string fragment_shader;
		std::string vertex_shader;

		GLuint programID;
		GLuint vertexPosition_modelspaceID;
		GLuint vertexUVID;
		GLuint colorID;
		GLuint matrixID;
		GLuint textureID;

		glm::mat4 modelMatrix;
		glm::mat4 projectionMatrix;

};

#endif /* RENDERER_H */
