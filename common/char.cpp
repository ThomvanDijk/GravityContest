#include "char.h"

Char::Char(const std::string& pathToChar) : Entity()
{
	Line* _character = new Line();

	// if the location is correctly and can be loaded
	if (_character->loadLineFile(pathToChar)) {
		addLine(_character);

		std::cout << "char created" << std::endl;
	}
}

Char::Char(const std::string& pathToChar, float r, float g, float b) : Entity()
{
	Line* _character = new Line();
	_character->setColor(r, g, b);

	// if the location is correctly and can be loaded
	if (_character->loadLineFile(pathToChar)) {
		addLine(_character);

		std::cout << "char created" << std::endl;
	}
}

Char::Char(const std::string& pathToChar, float r, float g, float b, float a) : Entity()
{
	Line* _character = new Line();
	_character->setColor(r, g, b, a);

	// if the location is correctly and can be loaded
	if (_character->loadLineFile(pathToChar)) {
		addLine(_character);

		std::cout << "char created" << std::endl;
	}
}
