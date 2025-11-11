#include "spaceObject.h"

// Default constructor
SpaceObject::SpaceObject()
	: position(), velocity(), angle(), secondsAlive(0), radius(0.0)
{
}

// Parameterized constructor
SpaceObject::SpaceObject(const Position& pos, const Velocity& vel, const Angle& ang, double rad)
	: position(pos), velocity(vel), angle(ang), secondsAlive(0), radius(rad)
{
}

// Getters
Position SpaceObject::getPosition() const
{
	return position;
}

Velocity SpaceObject::getVelocity() const
{
	return velocity;
}

Angle SpaceObject::getAngle() const
{
	return angle;
}

double SpaceObject::getRadius() const
{
	return radius;
}

// Setters
void SpaceObject::setPosition(const Position& pos)
{
	position = pos;
}

void SpaceObject::setVelocity(const Velocity& vel)
{
	velocity = vel;
}

void SpaceObject::setAngle(const Angle& ang)
{
	angle = ang;
}

void SpaceObject::setRadius(double rad)
{
	radius = rad;
}

// Behavior stubs (to be implemented)
void SpaceObject::applyGravity(const Position& center, double gravitationalConstant, double timeStep)
{
	// TODO: Apply gravitational acceleration based on the center position and gravitational constant
}

void SpaceObject::updatePosition(double timeStep)
{
	// TODO: Update position based on velocity and time step
}

void SpaceObject::rotate(double radians)
{
	// TODO: Adjust the angle by the given radians
}

void SpaceObject::updateObject()
{
	// TODO: General update behavior (e.g., move, rotate, age, etc.)
}

void SpaceObject::incrementSecondsAlive()
{
	++secondsAlive;
}

// draw() is pure virtual; no implementation here
