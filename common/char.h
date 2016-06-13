#ifndef CHAR_H
#define CHAR_H

#include <common/entity.h>

class Char : public Entity
{
	public:
		Char(const std::string& character);
		Char(const std::string& character, float r, float g, float b);
		Char(const std::string& character, float r, float g, float b, float a);

};

#endif /* CHAR_H */
