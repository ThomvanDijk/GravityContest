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

#include <vector>

#include <common/texture.h>
#include <common/point.h>

class Line
{
	public:
		Line(std::vector<Point*> pointArray);
		virtual ~Line();

		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint colorbuffer() { return _colorbuffer; };

	private:
		GLuint _vertexbuffer;
		GLuint _colorbuffer;
		
		//Point* pointArray[];
};

#endif /* LINE_H */
