/***********************************************************************
 * Source File:
 *    Dragon : The source information for the dragon satellite
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the dragon satellite.
 ************************************************************************/

#include "dragon.h"


 /***********************************************
 * DRAGON: Default Constructor
 *         Creates the dragon object
 ***********************************************/
Dragon::Dragon()
	: Satellite()
{
	Position pos(0.0, 8000000.0); // Approximate altitude of Dragon satellites
	Velocity vel(-7900.0, 0.0);     // Approximate orbital velocity
	Angle angle(0.0);
	setPosition(pos);
	setVelocity(vel);
	setAngle(angle);
	setRadius(7); // radius of Dragon satellite in pixels
}


/***********************************************
 * DRAGON: NonDefault Constructor
 *         Creates a dragon object
 ***********************************************/
Dragon::Dragon(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: Satellite(pos, vel, angle, radius)
{
}


/***********************************************
* DRAGON: Draw
*         Draws the dragon satellite
***********************************************/
void Dragon::draw(ogstream& ui) const
{
	// Drawing logic for Dragon satellite
	ui.drawCrewDragon(getPosition(), getAngle().getRadians());
}


/***********************************************
* DRAGON: Shatter
*         Shatters dragon into parts.
***********************************************/
void Dragon::shatter()
{
	// Logic for Dragon shattering
}