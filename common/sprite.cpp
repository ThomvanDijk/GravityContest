#include "common/sprite.h"

Sprite::Sprite()
{
	std::string texture_file = "assets/uvtemplate.DDS";

	// Load the texture (see: texture.h/cpp)
	_texture = loadDDS(texture_file.c_str());

	int sprite_width = 512;
	int sprite_height = 512;

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices.
	static const GLfloat g_vertex_buffer_data[] = {
		0.5f * sprite_width, -0.5f * sprite_height, 0.0f,
	   -0.5f * sprite_width, -0.5f * sprite_height, 0.0f,
	   -0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
	   -0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
		0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
		0.5f * sprite_width, -0.5f * sprite_height, 0.0f
	};

	// Two UV coordinates for each vertex.
	static const GLfloat g_uv_buffer_data[] = {
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

Sprite::~Sprite()
{
	// Cleanup VBO and shader
	glDeleteBuffers(1, &_vertexbuffer);
	glDeleteBuffers(1, &_uvbuffer);
}
