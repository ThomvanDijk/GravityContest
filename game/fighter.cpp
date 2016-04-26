#include "fighter.h"

using namespace std;

Fighter::Fighter() : Entity()
{
	cout << "new fighter created" << endl;

	vector2 = new Vector2(); // instance from Vector2 class

	location = Vector2(100, 200);
	velocity = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	mouse = Vector2(0, 0);
	direction = Vector2(0, 0);
	force = Vector2(0, 0);
	gravity = Vector2(0, 0.0001);
	friction = Vector2(0, 0);

	topspeed = 0.0001f;
	angle = 0.0f;

	accelerate = false;
}

Fighter::~Fighter()
{
	delete vector2;
}

void Fighter::update(float deltaTime)
{
	this->deltaTime = deltaTime;

	acceleration.add(gravity);
	if (accelerate) {
		acceleration.add(force.fromAngle(vector2->rad2deg(angle)));
		acceleration.multS(0.001);
	}

	float c = 0.1;
	float speed = velocity.mag();

	//cout << speed << endl;
	float dragMagnitude = c * speed * speed;

	Vector2 drag = velocity;
	friction = velocity;
	friction.multS(-1);
	//friction.normalize();
	friction.multS(dragMagnitude);

	acceleration.add(friction);

	velocity.add(acceleration);
	this->rotation = angle;
	location.add(velocity);
	acceleration.multS(0);

	position.x = location.x;
	position.y = location.y;

	accelerate = false;
	boundaries();
}

void Fighter::boundaries()
{
	if (position.y >= 600) {
		location.y = 600;
		velocity.multS(0);
	}
}

void Fighter::rotateLeft()
{
	angle -= 2 * deltaTime;
}

void Fighter::rotateRight()
{
	angle += 2 * deltaTime;
}
