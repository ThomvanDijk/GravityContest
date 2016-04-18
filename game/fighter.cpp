#include "fighter.h"

using namespace std;

Fighter::Fighter() : Entity()
{
	cout << "new fighter created" << endl;

	location = Vector2(100, 200);
	velocity = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	mouse = Vector2(0, 0);
	direction = Vector2(0, 0);
	force = Vector2(0, 0);
	gravity = Vector2(0, 0);

	topspeed = 0.0001f;
	angle = 0.0f;

	accelerate = false;
}

Fighter::~Fighter()
{
	
}

void Fighter::update(float deltaTime)
{
	acceleration.add(gravity);
	if (accelerate) {
		acceleration.add(force.fromAngle(rotation));
	}

	velocity.add(acceleration);
	//this->rotation = angle;
	location.add(velocity);
	acceleration.multS(0);

	position.x = location.x;
	position.y = location.y;

	accelerate = false;
}
