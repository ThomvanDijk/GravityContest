#ifndef CHAR_H
#define CHAR_H

#include <common/entity.h>

class Char : public Entity
{
	public:
		Char(const std::string& character);
		virtual ~Char();

};

#endif /* CHAR_H */
