/***********************************************************************
 * Source File:
 *    GPS : The source information for the GPS satellite
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the GPS satellite.
 ************************************************************************/


#include "gps.h"

/***********************************************
* GPS: Default Constructor
* Create a GPS satellite object
* Note: This constructor should not be used, as there 
* need to be 6 independent GPS satellites
***********************************************/
GPS::GPS()
	: Satellite()
{
	Position pos(0.0, -2020000000.0); // Approximate altitude of GPS satellites
	Velocity vel(0.0, 0.0);     // Approximate orbital velocity
	Angle angle(0.0);
	setPosition(pos);
	setVelocity(vel);
	setAngle(angle);
	setRadius(12); // radius of GPS satellite in pixels
}



/***********************************************
 * GPS: NonDefault Constructor
 *      Creates a GPS object
 ***********************************************/
GPS::GPS(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	//: Satellite(pos, vel, angle, radius)
{

	setPosition(pos);
	setVelocity(vel);
	setRadius(radius);

	Angle d;
	d.setRadians(atan2(pos.getMetersY(), -pos.getMetersX()));
	setAngle(d);


}


/***********************************************
* GPS: Draw
*      Draws the GPS satellite
***********************************************/
void GPS::draw(ogstream& ui) const
{
	// Drawing logic for GPS satellite
	ui.drawGPS(getPosition(), getAngle().getRadians());
}


/***********************************************
* GPS: Shatter
*      Shatters GPS into parts
***********************************************/
void GPS::shatter()
{
	// Logic for GPS shattering
}