#include "text.h"

Text::Text() : Entity()
{
	
}

Text::Text(const std::string& text) : Entity()
{
	_spacing = 40;

	for (int i = 0; i < text.size(); i++) {
		// holds the path to the character
		char path[40];

		// changes %c to text[i] and puts the whole path in buf
		sprintf(path, "fonts/%c.line", text[i]);

		// creata a new char if it isn't a space
		if (text[i] != 32) {
			Char* _newCharacter = new Char(path, 255, 64, 10);
			addChild(_newCharacter);

			// add spacing between chars
			_newCharacter->position.x += i * _spacing;
		}
	}
}
