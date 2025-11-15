/***********************************************************************
 * Source File:
 *    Hubble : The source information for the hubble satellite
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the hubble satellite.
 ************************************************************************/

#include "hubble.h"


 /***********************************************
 * HUBBLE : Default Constructor
 *         Creates the hubble object
 ***********************************************/
Hubble::Hubble()
	: Satellite()
{
	Position pos(0.0, -42164000.0);
	Velocity vel(3100.0, 0.0);
	Angle angle(0.0);
	setPosition(pos);
	setVelocity(vel);
	setAngle(angle);
}


/***********************************************
 * HUBBLE : NonDefault Constructor
 *         Creates a hubble object
 ***********************************************/
Hubble::Hubble(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: Satellite(pos, vel, angle, radius)
{
}

/***********************************************
* HUBBLE : Draw
*         Draws the hubble satellite
***********************************************/
void Hubble::draw(ogstream& ui) const
{
	// Drawing logic for Hubble telescope
	ui.drawHubble(getPosition(), getAngle().getRadians());
}


/***********************************************
* HUBBLE : Shatter
*         Shatters hubble into parts.
***********************************************/
void Hubble::shatter()
{
	// Logic for Hubble shattering
}