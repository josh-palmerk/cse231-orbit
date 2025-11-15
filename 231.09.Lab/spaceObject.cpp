/***********************************************************************
 * Source File:
 *    Space Object : The base class for all interactive objects in space
 * Author:
 *    Garrin and Josh
 * Summary:
 *    All the characteristics of satellites space trash and other interactive objects.
 ************************************************************************/

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
	double dx = center.getMetersX() - position.getMetersX();
	double dy = center.getMetersY() - position.getMetersY();
	double distanceSquared = dx * dx + dy * dy;
	double distance = sqrt(distanceSquared);
	if (distance == 0) return; // Prevent division by zero
	double forceMagnitude = gravitationalConstant / distanceSquared;
	double ax = forceMagnitude * (dx / distance);
	double ay = forceMagnitude * (dy / distance);
	Acceleration acc(ax, ay);
	velocity.add(acc, timeStep);

}


/***********************************
* SPACEOBJECT: updatePosition
* Updates the position of the space object based on its velocity and the time step.
* **********************************/
void SpaceObject::updatePosition(double timeStep)
{
	// TODO: Update position based on velocity and time step
	position.addMetersX(velocity.getDX() * timeStep);
	position.addMetersY(velocity.getDY() * timeStep);

}


/***********************************
* SPACEOBJECT: rotate
* Rotates the space object by the specified radians.
***********************************/
void SpaceObject::rotate(double radians)
{
	this->angle.add(radians);
}


void SpaceObject::updateObject(double timestep)
{
	// TODO: General update behavior (e.g., move, rotate, age, etc.)
	applyGravity(Position(0, 0), 398600441800000.0, timestep); // Example gravitational constant for Earth)
	updatePosition(timestep);
	incrementSecondsAlive(static_cast<int>(timestep));
}


void SpaceObject::incrementSecondsAlive(int amount)
{
	secondsAlive += amount;
}

// draw() is pure virtual; no implementation here
