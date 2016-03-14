#include <common/entity.h>

Entity::Entity()
{
	position = new Point(0, 0);
	_sprite = new Sprite();
}

Entity::~Entity()
{
	delete position;
	delete _sprite;
}
