#include "text.h"

Text::Text() : Entity()
{
	_character = new Line();
	_character->loadLineFile("fonts/a.line");
	_character->setColor(1,1,0,1);
	addLine(_character);
}

Text::Text(const std::string& text) : Entity()
{
	for (int i = 0; i < text.size(); i++) {
		_character = new Line();

		char buf[100];
		sprintf(buf, "/path/to/%c.ext", text[i]);
		std::cout << buf << std::endl;
		/*
		// the location of the character
		std::string location = "fonts/"; // folder
		location.append(&text[i]); // character
		location.append(".line"); // extension

		std::cout << location << std::endl;

		// if the location is correctly loaded
		if (_character->loadLineFile(location)) {
			_character->setColor(1, 1, 0, 1);
			addLine(_character);
		}
		*/
	}
}

Text::~Text()
{
	
}
