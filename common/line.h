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
		void Line::setVertexBuffer(int i, float x, float y);

		void Line::setColor(float r, float g, float b, float a);
		glm::vec4 Line::getColor() { return _color; };

		GLuint vertexbuffer() { return _vertexbuffer; };
		GLuint colorbuffer() { return _colorbuffer; };

		int getNumberOfPoints() { return _numberOfPoints; };

		bool loadLineFile(const std::string& filename);

	private:
		GLuint _vertexbuffer;
		GLuint _colorbuffer;

		int _numberOfPoints;

		glm::vec4 _color;

		std::vector<GLfloat> _vertex_buffer_data;

};

#endif /* LINE_H */
