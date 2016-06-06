#include "text.h"

Text::Text() : Entity()
{
	
}

Text::Text(const std::string& text) : Entity()
{
	for (int i = 0; i < text.size(); i++) {
		_character = new Line();

		// holds the path to the char
		char buf[40];

		// changes %c to text[i] and puts the whole path in buf
		sprintf(buf, "fonts/%c.line", text[i]);

		// if the location is correctly and can be loaded
		if (_character->loadLineFile(buf)) {
			_character->setColor(1, 1, 0, 1);
			for (int i = 0; i < _character->getNumberOfPoints(); i++) {
				_character->setVertexBuffer(i, 35);
			}
			
			addLine(_character);
		}
	}
}

Text::~Text()
{
	
}
