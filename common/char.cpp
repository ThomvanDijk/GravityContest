#include "char.h"

Char::Char(const std::string& pathToChar) : Entity()
{
	_character = new Line();

	std::cout << "char created" << std::endl;

	// if the location is correctly and can be loaded
	if (_character->loadLineFile(pathToChar)) {
		_character->setColor(1, 1, 0, 1);
		addLine(_character);
	}
}

Char::~Char()
{
	delete _character;
}
