#include "fighter.h"

using namespace std;

Fighter::Fighter() : Entity()
{
	cout << "new fighter created" << endl;

	// spaceship body
	body = new Line();
	body->addPoint(Point(-20, 10));
	body->addPoint(Point(30, 0));
	body->addPoint(Point(-20, -10));
	body->setColor(1, 1, 1, 1); // for now the values range from 0 to 1
	
	// spaceship exhaust
	exhaust = new Line();
	exhaust->addPoint(Point(-20, 8));
	exhaust->addPoint(Point(-25, 0));
	exhaust->addPoint(Point(-20, -8));
	exhaust->setColor(1, 0.5, 0, 1);

	// the first added line is drawn first
	addLine(exhaust);
	addLine(body);

	vector2 = new Vector2(); // instance from Vector2 class

	location = Vector2(400, 600);
	velocity = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	mouse = Vector2(0, 0);
	direction = Vector2(0, 0);
	force = Vector2(0, 0);
	gravity = Vector2(0, 0.0001);
	friction = Vector2(0, 0);
	drag = Vector2();

	topspeed = 0.0001f;
	angle = M_PI + M_PI / 2; // 270 degrees

	// for friction
	constant = 0.05;
	dragMagnitude = 0;
	speed = 0;

	accelerate = false;
}

Fighter::~Fighter()
{
	delete vector2;
}

void Fighter::update(float deltaTime)
{
	this->deltaTime = deltaTime;

	exhaust->setVertexBuffer(3, -25);

	if (accelerate) {
		acceleration.add(force.fromAngle(vector2->rad2deg(angle)));
		acceleration.multS(0.001);

		exhaust->setVertexBuffer(3, -45);
	}

	// for the friction
	speed = velocity.mag();
	dragMagnitude = constant * speed * speed;

	drag = velocity;
	friction = velocity;
	friction.multS(-1);
	//friction.normalize();
	friction.multS(dragMagnitude);
	acceleration.add(friction);

	acceleration.add(gravity);

	velocity.add(acceleration);
	this->rotation = angle;
	location.add(velocity);
	acceleration.multS(0);

	std::cout << speed << endl;

	position.x = location.x;
	position.y = location.y;

	accelerate = false;
	boundaries();
}

void Fighter::boundaries()
{
	if (position.y >= 599) {
		location.y = 599;
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
