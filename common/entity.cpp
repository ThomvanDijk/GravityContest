#include <common/entity.h>

int Entity::_nextGuid = 0;

Entity::Entity()
{
	_guid = _nextGuid;
	_nextGuid++;

	_parent = NULL;

	position = Point(0.0f, 0.0f);
	rotation = 0.0f;
	scale = Point(1.0f, 1.0f);
}

Entity::~Entity()
{
	std::cout << "destructor entity" << std::endl;

	// delete all childeren
	for (int i = 0; i < _children.size(); i++) {
		delete _children[i];
	}

	// delete all lines
	for (int i = 0; i < _lineList.size(); i++) {
		delete _lineList[i];
	}

	_children.clear();
	_lineList.clear();
}

void Entity::addLine(Line* line)
{
	// Lines are added so the renderer knows what to render.
	_lineList.push_back(line);
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
