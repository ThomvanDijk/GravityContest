#include <common/entity.h>

Entity::Entity()
{
	position = Point(0, 0);
	_line = new Line();
}

Entity::~Entity()
{
	delete _line;
}
