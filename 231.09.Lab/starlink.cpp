/***********************************************************************
 * Source File:
 *    Starlink : The source information for the starlink satellite
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the starlink satellite.
 ************************************************************************/

#include "starlink.h"


/***********************************************
* STARLINK: Default Constructor
* Create a Starlink satellite object
***********************************************/
Starlink::Starlink()
	: Satellite()
{
	Position pos(0.0, -13020000.0); // Approximate altitude of Starlink satellites
	Velocity vel(5800.0, 0.0);     // Approximate orbital velocity
	Angle angle(0.0);
	setPosition(pos);
	setVelocity(vel);
	setAngle(angle);
	setRadius(6); // radius of Starlink satellite in pixels
}


/***********************************************
 * STARLINK: NonDefault Constructor
 *           Creates a starlink object
 ***********************************************/
Starlink::Starlink(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: Satellite(pos, vel, angle, radius)
{
}

/***********************************************
* STARLINK: Draw
*           Draws the starlink satellite
***********************************************/
void Starlink::draw(ogstream& ui) const
{
	// Drawing logic for Starlink satellite
	ui.drawStarlink(getPosition(), getAngle().getRadians());
}


/***********************************************
* STARLINK: Shatter
*           Shatters starlink into parts.
***********************************************/
void Starlink::shatter(vector<SpaceObject*>& spaceObjects)
{
	// Logic for Starlink shattering
}

/***********************************************
* STARLINK: Die
*           Sets Starlink to dead
***********************************************/
void Starlink::die()
{
	dead = true;
}