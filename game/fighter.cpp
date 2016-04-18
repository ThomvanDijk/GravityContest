#include "fighter.h"

using namespace std;

Fighter::Fighter() : Entity()
{
	cout << "new fighter created" << endl;

	location = new Vector2(100, 200);
	
}

Fighter::~Fighter()
{
	
}

void Fighter::update(float deltaTime)
{
	position.x = location->x;
	position.y = location->y;
}
