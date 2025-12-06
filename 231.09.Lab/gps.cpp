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
	setRadius(12 * 128000.0); // radius of GPS satellite in pixels
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
void GPS::shatter(vector<SpaceObject*>& spaceObjects)
{
    // Logic for GPS shattering
    // center r7 left 8 right 8 3 frags each

    ogstream ui;
    spaceObjects.push_back(new Part(
        getPosition(), getVelocity(), getAngle(), 7.0,
        [&ui](const Position& pos, double rot, const Position& offset) { ui.drawGPSCenter(pos, rot); }, 3));
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 8.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawGPSLeft(pos, rot, offset); }, 3));
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 8.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawGPSRight(pos, rot, offset); }, 3));

    spaceObjects.push_back(new Fragment(getPosition(), getVelocity(), getAngle(), 2.0, false));
    spaceObjects.push_back(new Fragment(getPosition(), getVelocity(), getAngle(), 2.0, false));
	die();
    // remove self here?
}

/***********************************************
* GPS: Die
*      Sets the GPS to dead
***********************************************/
void GPS::die()
{
	dead = true;
}