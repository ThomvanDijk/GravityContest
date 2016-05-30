#include <common/entity.h>

Entity::Entity()
{
	position = Point(0.0f, 0.0f);
	rotation = 0.0f;
	scale = Point(1.0f, 1.0f);

}

Entity::~Entity()
{

}

void Entity::addLine(Line* line)
{
	// Lines are added so the renderer knows what to render.
	lineList.push_back(line);
}
