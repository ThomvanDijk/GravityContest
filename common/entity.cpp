#include <common/entity.h>

int Entity::_nextGuid = 0;

Entity::Entity()
{
	position = new Point(0, 0);

	_guid = _nextGuid;
	_nextGuid++;

	_parent = NULL;
	_sprite = new Sprite();
}

Entity::~Entity()
{
	delete position;
	delete _sprite;
}

void Entity::addChild(Entity* child)
{
	if (child->_parent != NULL) {
		child->_parent->removeChild(child);
	}
	child->_parent = this;
	this->_children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
	std::vector< Entity* >::iterator it = _children.begin();
	while (it != _children.end()) {
		if ((*it)->_guid == child->_guid) {
			it = _children.erase(it);
		}
		else {
			++it;
		}
	}
}

Entity* Entity::getChild(unsigned int i)
{
	if (i < _children.size()) {
		return _children[i];
	}
	return NULL;
}