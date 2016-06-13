#ifndef TEXT_H
#define TEXT_H

#include <common/entity.h>
#include <common/char.h>

class Text : public Entity
{
	public:
		Text();
		Text(const std::string& text);

		float spacing;

};

#endif /* TEXT_H */
