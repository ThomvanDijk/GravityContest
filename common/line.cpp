#include "line.h"

Line::Line()
{
	// default color is white
	_color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	_numberOfPoints = 0;
}

Line::~Line()
{
	glDeleteBuffers(1, &_vertexBuffer);

	/*for (int i = 0; i < _vertexList.size(); i++) {
		delete &_vertexList[i];
	}

	_vertexList.clear();*/
}

void Line::setColor(float r, float g, float b)
{
	r /= 255; // convert to a value between 0 and 1
	g /= 255;
	b /= 255;

	_color.r = r;
	_color.g = g;
	_color.b = b;
}

void Line::setColor(float r, float g, float b, float a)
{
	r /= 255; // convert to a value between 0 and 1
	g /= 255;
	b /= 255;
	a /= 255;

	_color = glm::vec4(r, g, b, a);
}

void Line::setVertexBuffer(int i, float x, float y) 
{ 
	_vertexList[i * 3] = x;
	_vertexList[i * 3 + 1] = y;

	bindPoints();
}

void Line::addPoint(Point point)
{
	// Here the points are defined where the lines are drawn between.
	_vertexList.push_back(point.x);
	_vertexList.push_back(point.y);
	_vertexList.push_back(0.0f);

	// save the number of points added
	_numberOfPoints++;

	bindPoints();
}

void Line::bindPoints()
{
	// first delete the old buffer
	glDeleteBuffers(1, &_vertexBuffer);

	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, _vertexList.size() * sizeof(GLfloat), &_vertexList[0], GL_STATIC_DRAW);
}

bool Line::loadLineFile(const std::string& filename)
{
	FILE* file = fopen(filename.c_str(), "r");
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

		// else: parse lineHeader
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
	return true;
}
