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
	setRadius(7 * 128000.0); // radius of Dragon satellite in pixels
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
void Dragon::shatter(vector<SpaceObject*>& spaceObjects)
{
	ogstream ui;
	// Logic for Dragon shattering
	// center rad 6 4 frags
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 6.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawCrewDragonCenter(pos, rot); }, 4));
	// right rad 6 2 frags
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 6.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawCrewDragonRight(pos, rot); }, 2));
	// left rad 6 2 frags
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 6.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawCrewDragonLeft(pos, rot); }, 2));
}

/***********************************************
* DRAGON: Die
*         Sets the dragon to dead
***********************************************/
void Dragon::die()
{
	dead = true;
}