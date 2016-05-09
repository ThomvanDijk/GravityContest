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
		Line();
		virtual ~Line();

		void Line::addPoint(Point point);
		void Line::bindPoints();

		std::vector<GLfloat> getVertexBuffer() { return _vertex_buffer_data; };
		void Line::setVertexBuffer(int i, float f);

		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint colorbuffer() { return _colorbuffer; };

	private:
		GLuint _vertexbuffer;
		GLuint _colorbuffer;

		std::vector<GLfloat> _vertex_buffer_data;

};

#endif /* LINE_H */
