#ifndef TEXT_H
#define TEXT_H

#include <common/entity.h>

class Text : public Entity
{
	public:
		Text();
		Text(const std::string& text);
		virtual ~Text();

	private:
		Line* _character;

};

#endif /* TEXT_H */
