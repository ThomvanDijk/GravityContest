#include "line.h"

Line::Line()
{
	// default color is white
	_color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
}

Line::~Line()
{
	glDeleteBuffers(1, &_vertexbuffer);
}

void Line::setColor(float r, float g, float b, float a)
{
	_color = glm::vec4(r, g, b, a);
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

bool Line::loadLineFile(const std::string& filename)
{
	FILE * file = fopen(filename.c_str(), "r");
	if (file == NULL) {
		printf("Can't open %s\n", filename.c_str());
		return false;
	}

	while (1) {
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF) {
			break; // EOF = End Of File. Quit the loop.
		}

		// else : parse lineHeader
		if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			int matches = fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			if (matches != 3) {
				printf("File can't be read by the parser. Not 3 vertices per point.\n");
				return false;
			}
			addPoint(Point(vertex.x, vertex.y));
		}
		else {
			// Probably a comment, eat up the rest of the line
			char tmpBuffer[1000];
			char * returned = fgets(tmpBuffer, 1000, file);
			if (returned[0] == '#') {
				// yes, a comment
			}
		}
	}

	fclose(file);

	// close the line, maybe not necessary
	//_points.push_back(_points[0]);
	//addPoint(Point(-85.1355, 24.9158));

	return true;
}
