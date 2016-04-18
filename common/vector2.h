#ifndef VECTOR2_H
#define VECTOR2_H

// use this for the C++ math functions
#define _USE_MATH_DEFINES

#include <math.h>

class Vector2
{
	public:
		Vector2(float xx, float yy);
		Vector2() {};

		Vector2 Vector2::setTo(float xx, float yy);
		Vector2 Vector2::create(float begin, float end);
		Vector2 Vector2::fromAngle(float angle);
		Vector2 Vector2::copy();

		// info (getters)
		float Vector2::mag();
		float Vector2::magSq();
		float Vector2::dist(Vector2 other);
		Vector2 Vector2::getNormalized();
		Vector2 Vector2::normalize();
		Vector2 Vector2::limit(float max);
		Vector2 Vector2::setMag(float magnitude);
		float Vector2::getAngle();
		float Vector2::getAngleToVector(Vector2 other);
		float Vector2::dot(Vector2 other);

		// manipulators
		Vector2 Vector2::rotate(float angle);
		Vector2 Vector2::add(Vector2 other);
		Vector2 Vector2::sub(Vector2 other);
		Vector2 Vector2::mult(Vector2 other);
		Vector2 Vector2::multS(float scalar);
		Vector2 Vector2::div(Vector2 other);
		Vector2 Vector2::divS(float scalar);
		float Vector2::rad2deg(float a);
		float Vector2::deg2rad(float a);

		float x;
		float y;

};

#endif /* VECTOR2_H */