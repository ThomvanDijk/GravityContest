#include <common/entity.h>

Entity::Entity()
{
	position = Point(0.0f, 0.0f);
	rotation = 0.0f;
	scale = Point(1.0f, 1.0f);

	float floatArray[] = {
		  0.0f, -25.0f, 0.0f,
		 15.0f,  25.0f, 0.0f,
		-15.0f,  25.0f, 0.0f
	};

	std::vector<Point*> pointArray;
	pointArray.push_back(new Point(0, 10));
	pointArray.push_back(new Point(50, 0));
	pointArray.push_back(new Point(0, -10));

	// give an array of points to the line
	_line = new Line(pointArray);
}

Entity::~Entity()
{
	delete _line;
}
