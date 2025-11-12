#include "spaceObject.h"


// Default constructor
SpaceObject::SpaceObject()
	: position(Position(0, 0)), velocity(Velocity(0, 0)), angle(Angle(0)), secondsAlive(0), radius(0.0)
{
}


// Parameterized constructor
SpaceObject::SpaceObject(const Position& pos, const Velocity& vel, const Angle& ang, double rad)
	: position(pos), velocity(vel), angle(ang), secondsAlive(0), radius(rad)
{
}


// Behavior stubs (to be implemented)
void SpaceObject::applyGravity(const Position& center, double gravitationalConstant, double timeStep)
{
	// TODO: Apply gravitational acceleration based on the center position and gravitational constant
}


/***********************************
* SPACEOBJECT: updatePosition
* Updates the position of the space object based on its velocity and the time step.
* **********************************/
void SpaceObject::updatePosition(double timeStep)
{
	// TODO: Update position based on velocity and time step
}


/***********************************
* SPACEOBJECT: rotate
* Rotates the space object by the specified radians.
***********************************/
void SpaceObject::rotate(double radians)
{
	this->angle.add(radians);
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
