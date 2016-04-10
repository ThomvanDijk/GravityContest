#include <common/entity.h>

Entity::Entity()
{
	position = Point(0.0f, 0.0f);
	rotation = 0.0f;
	scale = Point(1.0f, 1.0f);

	_line = new Line();
}

Entity::~Entity()
{
	delete _line;
}
