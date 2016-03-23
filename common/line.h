#ifndef LINE_H
#define LINE_H

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

#include <common/texture.h>
#include <common/point.h>

class Line
{
	public:
		Line();
		virtual ~Line();

		GLuint vertexbuffer() { return _vertexbuffer; };

	private:
		GLuint _vertexbuffer;
};

#endif /* LINE_H */
