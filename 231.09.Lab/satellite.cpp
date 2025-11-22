/***********************************************************************
 * Source File:
 *    Satellite : The base class for all satellites
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The base class for all satellite objects, inherits space object.
 ************************************************************************/

#include "satellite.h"


 /***********************************************
 * SATTELITE: Default Constructor
 * Create a satellite object
 ***********************************************/
Satellite::Satellite()
	: SpaceObject(), defunct(false)
{
	Angle d;
	d.setRadians(atan2(-position.getMetersY(), -position.getMetersX()) + M_PI_2);
	setAngle(d);
}


/***********************************************
* SATTELITE: NonDefault Constructor
* Create a satellite object with parameters.
***********************************************/
Satellite::Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	//: SpaceObject(pos, vel, angle, radius), defunct(false)
{
	setPosition(pos);
	setVelocity(vel);
	setRadius(radius);
	defunct = false;

	Angle d;
	d.setRadians(atan2(-position.getMetersY(), -position.getMetersX()) + M_PI_2);
	setAngle(d);
}


/***********************************************
* SATELLITE: Update Object
* Updates the details of the satellite
***********************************************/
void Satellite::updateObject(double timestep)
{
	applyGravity(Position(0, 0), 398600441800000.0, timestep); // Example gravitational constant for Earth)
	updatePosition(timestep);
	incrementSecondsAlive(static_cast<int>(timestep));
	if (!defunct) {
		Angle d;
		d.setRadians(atan2(position.getMetersY(), -position.getMetersX()));
		setAngle(d);
	}
	else rotate(0.01);
}
