#include "line.h"

Line::Line()
{
	// Here the point where the lines are drawn between are defined
	GLfloat g_vertex_buffer_data[] = {
		 100.5f  , -0.5f  , 0.0f,
		-0.5f  , -0.5f  , 0.0f,
		-0.5f  ,  0.5f  , 0.0f,
		-0.5f  ,  0.5f  , 0.0f,
		 0.5f  ,  0.5f  , 0.0f,
		 0.5f  , -0.5f  , 0.0f
	};

	glGenBuffers(1, &_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

Line::~Line()
{
	glDeleteBuffers(1, &_vertexbuffer);
}
