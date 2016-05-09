#include "line.h"

Line::Line()
{
	
}

Line::~Line()
{
	glDeleteBuffers(1, &_vertexbuffer);
}

void Line::setVertexBuffer(int i, float f) 
{ 
	_vertex_buffer_data[i] = f;

	bindPoints();
}

void Line::addPoint(Point point)
{
	// Here the points are defined where the lines are drawn between.
	_vertex_buffer_data.push_back(point.x);
	_vertex_buffer_data.push_back(point.y);
	_vertex_buffer_data.push_back(0.0f);

	bindPoints();
}

void Line::bindPoints()
{
	// first delete the old buffer
	glDeleteBuffers(1, &_vertexbuffer);

	glGenBuffers(1, &_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, _vertex_buffer_data.size() * sizeof(GLfloat), &_vertex_buffer_data[0], GL_STATIC_DRAW);
}
