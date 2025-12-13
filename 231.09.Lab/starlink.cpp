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
	setRadius(6 * 128000.0); // radius of Starlink satellite in pixels
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

	// body rad 2 3 frags
	spaceObjects.push_back(new Part(
		Position(40000000.0, 40000000.0), getVelocity(), getAngle(), 2.0,
		STARLINK_BODY));

	// array rad 4 3 frags
	//spaceObjects.push_back(new Part(getPosition(), getVelocity(), getAngle(), 4.0,STARLINK_ARRAY));
}

