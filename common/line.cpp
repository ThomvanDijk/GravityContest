#include "line.h"

Line::Line(std::vector<Point*> pointArray)
{
	int vertex_buffer_length = pointArray.size();
	// Here the point where the lines are drawn between are defined
	GLfloat g_vertex_buffer_data[] = { 
		pointArray[0]->x, pointArray[0]->y, 0.0f,
		pointArray[1]->x, pointArray[1]->y, 0.0f,
		pointArray[2]->x, pointArray[2]->y, 0.0f,
		//pointArray[3]->x, pointArray[3]->y, 0.0f,
	};
		//0.0f, //-25.0f, 0.0f
		// 15.0f,  25.0f, 0.0f,
		//-15.0f,  25.0f, 0.0f
	

	/*for (int i = 0; i < pointArray.size(); i++) {
		g_vertex_buffer_data[i] = pointArray[i]->x;
		g_vertex_buffer_data[i+1] = pointArray[i]->y;
		g_vertex_buffer_data[i+2] = 0.0f;
	}*/

	glGenBuffers(1, &_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

Line::~Line()
{
	glDeleteBuffers(1, &_vertexbuffer);
}
