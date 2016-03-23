#include <common/entity.h>

Entity::Entity()
{
	position = Point(0, 0);
	_sprite = new Sprite();
	_line = new Line();
}

Entity::~Entity()
{
	//delete position;
	delete _sprite;
	delete _line;
}
