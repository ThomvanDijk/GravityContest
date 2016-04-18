#include <common/vector2.h>

Vector2::Vector2(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
}

// ####################################################
// methods
// ####################################################

//Vector2 Vector2::setTo(float xx, float yy) {
//	// TODO implement
//	return NULL;
//}

//Vector2 Vector2::create(float begin, float end) {
//	// TODO implement
//	return NULL;
//}

Vector2 Vector2::fromAngle(float angle) {
	angle *= (M_PI / 180);
	this->x = cos(angle);
	this->y = sin(angle);
	return *this;
}

Vector2 Vector2::copy() {
	return Vector2(this->x, this->y);
}

// info (getters)
float Vector2::mag() {
	float getal = (x*x) + (y*y);
	float pos = sqrt(getal);
	return pos;
}

//float Vector2::magSq() {
//	// TODO implement
//	return 0;
//}

//float Vector2::dist(Vector2 other) {
//	// TODO implement
//	return 0;
//}

Vector2 Vector2::getNormalized() {
	Vector2* t = new Vector2(this->x, this->y);
	t->normalize();
	return *t;
}

Vector2 Vector2::normalize() {
	float m = this->mag();
	this->x = this->x / m;
	this->y = this->y / m;
	return *this;
}

Vector2 Vector2::limit(float max) {
	if (this->mag() > max) {
		this->normalize();
		this->multS(max);
	}
	return *this;
}

//Vector2 Vector2::setMag(float magnitude) {
//	// TODO implement
//	return NULL;
//}

float Vector2::getAngle() {
	float angle = atan2(y, x);
	return angle * (180 / M_PI);
}

//float Vector2::getAngleToVector(Vector2 other) {
//	// TODO implement
//	return 0;
//}

//float Vector2::dot(Vector2 other) {
//	// TODO implement
//	return 0;
//}

// manipulators
//Vector2 Vector2::rotate(float angle) {
//	// TODO implement
//	return NULL;
//}

Vector2 Vector2::add(Vector2 other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2 Vector2::sub(Vector2 other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2 Vector2::mult(Vector2 other) {
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

Vector2 Vector2::multS(float scalar) {
	this->x *= scalar;
	this->y *= scalar;
	return *this;
}

Vector2 Vector2::div(Vector2 other) {
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}

Vector2 Vector2::divS(float scalar) {
	this->x /= scalar;
	this->y /= scalar;
	return *this;
}

float Vector2::rad2deg(float a) {
	return a * (180 / M_PI);
}

float Vector2::deg2rad(float a) {
	return a * (M_PI / 180);
}
