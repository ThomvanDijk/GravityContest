#ifndef TEXT_H
#define TEXT_H

#include <common/entity.h>
#include <common/char.h>

class Text : public Entity
{
	public:
		Text();
		Text(const std::string& text);
		virtual ~Text();

		float spacing;

	private:
		//Char* _newCharacter;

};

#endif /* TEXT_H */
