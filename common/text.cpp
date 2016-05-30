#include "text.h"

Text::Text() : Entity()
{
	position.x = 300;
	position.y = 300;
	_character = new Line();
	_character->loadLineFile("fonts/a.line");
	_character->setColor(1,1,0,1);
	addLine(_character);
}

Text::~Text()
{
	
}
