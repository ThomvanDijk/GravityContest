#ifndef TEXT_H
#define TEXT_H

#include <common/entity.h>
#include <common/char.h>

class Text : public Entity
{
	public:
		Text();
		Text(const std::string& text);

		float getSpacing() { return _spacing; }
		void setSpacing(float f) { _spacing = f; }

	private:
		float _spacing;

};

#endif /* TEXT_H */
