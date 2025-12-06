/***********************************************************************
 * Source File:
 *    Sputnik : The source information for the sputnik satellite
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the sputnik satellite.
 ************************************************************************/

#include "sputnik.h"


 /***********************************************
 * SPUTNIK: Default Constructor
 *          Creates the sputnik object
 ***********************************************/
Sputnik::Sputnik()
	: Satellite()
{
	Position pos(-36515095.13, 21082000.0); // Approximate low Earth orbit altitude
	Velocity vel(2050.0, 2684.68);    // Approximate orbital velocity
	Angle angle(0.0);
	setPosition(pos);
	setVelocity(vel);
	setAngle(angle);
	setRadius(4 * 128000.0); // radius of Sputnik converted to meters
}


/***********************************************
 * SPUTNIK: NonDefault Constructor
 *          Creates a sputnik object
 ***********************************************/
Sputnik::Sputnik(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: Satellite(pos, vel, angle, radius)
{
}

/***********************************************
* SPUTNIK: Draw
*          Draws the sputnik satellite
***********************************************/
void Sputnik::draw(ogstream& ui) const
{
	// Drawing logic for Sputnik satellite
	ui.drawSputnik(getPosition(), getAngle().getRadians());
}


/***********************************************
* SPUTNIK: Shatter
*          Shatters sputnik into parts.
***********************************************/
void Sputnik::shatter(vector<SpaceObject*>& spaceObjects)
{
	// Logic for Sputnik shattering
	spaceObjects.push_back(new Fragment(getPosition(), getVelocity(), getAngle(), 2.0, false));
	spaceObjects.push_back(new Fragment(getPosition(), getVelocity(), getAngle(), 2.0, false));
	spaceObjects.push_back(new Fragment(getPosition(), getVelocity(), getAngle(), 2.0, false));
	spaceObjects.push_back(new Fragment(getPosition(), getVelocity(), getAngle(), 2.0, false));
	// remove self here?
}


