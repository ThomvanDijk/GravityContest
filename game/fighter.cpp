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
	exhaust->addPoint(Point(-20, 0));
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
	gravity = Vector2(0, 0.0005);
	friction = Vector2(0, 0);
	drag = Vector2(0, 0);

	// for friction
	constant = 0.05;
	dragMagnitude = 0;
	speed = 0;

	exhaustLength = -20;
	angle = M_PI + M_PI / 2; // 270 degrees
	timer = 0;
	deltaTime = 0;

	accelerate = false;
}

Fighter::~Fighter()
{
	delete vector2;
}

void Fighter::update(float deltaTime)
{
	this->deltaTime = deltaTime;

	if (exhaustLength < -20) {
		exhaustLength += 200 * deltaTime;
	}

	if (accelerate) {
		acceleration.add(force.fromAngle(vector2->rad2deg(angle)));
		acceleration.multS(0.0007);
		exaustAnimation();
	}

	// set the length of the exhaust
	exhaust->setVertexBuffer(3, exhaustLength);

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

	//std::cout << randNum << endl;

	position.x = location.x;
	position.y = location.y;

	accelerate = false;
	boundaries();
}

void Fighter::exaustAnimation()
{
	timer += 30 * deltaTime;

	if (timer >= 0 && timer <= 1) {
		exhaustLength = -60;
	}
	if (timer > 1 && timer <= 2) {
		exhaustLength = -54;
	}
	if (timer > 2) {
		timer = 0;
	}
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
