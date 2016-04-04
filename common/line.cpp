#include "line.h"

Line::Line()
{
	scale = 100;

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
	GLfloat g_vertex_buffer_data[] = {
		 0.5f * scale, -0.5f * scale, 0.0f,
		-0.5f * scale, -0.5f * scale, 0.0f,
		-0.5f * scale,  0.5f * scale, 0.0f,
		-0.5f * scale,  0.5f * scale, 0.0f,
		 0.5f * scale,  0.5f * scale, 0.0f,
		 0.5f * scale, -0.5f * scale, 0.0f
	};

	GLfloat g_color_buffer_data[] = {
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f
	};

	glGenBuffers(1, &_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &_colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
}

Line::~Line()
{
	glDeleteBuffers(1, &_vertexbuffer);
	glDeleteBuffers(1, &_colorbuffer);
}
