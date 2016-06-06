#include "text.h"

Text::Text() : Entity()
{
	
}

Text::Text(const std::string& text) : Entity()
{
	for (int i = 0; i < text.size(); i++) {
		// holds the path to the char
		char buf[40];

		// changes %c to text[i] and puts the whole path in buf
		sprintf(buf, "fonts/%c.line", text[i]);

		// creata a new char
		_newCharacter = new Char(buf);
		addChild(_newCharacter);
		_newCharacter->position.x += i * 40;
	}
}

Text::~Text()
{
	
}
