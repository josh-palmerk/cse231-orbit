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
	setRadius(10 * 128000.0); //  radius of Hubble in meters
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
void Hubble::shatter(vector<SpaceObject*>& spaceObjects)
{
	ogstream ui;
	// Logic for Hubble shattering: 
	// telescope rad 10 3 frags
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 10.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawHubbleTelescope(pos, rot); }, 3));

	// computer rad 7 2 frags
	
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 7.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawHubbleComputer(pos, rot); }, 2));

	// left rad 8 2 frags
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 8.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawHubbleLeft(pos, rot, offset); }, 2));
	// right rad 8 2 frags
	spaceObjects.push_back(new Part(
		getPosition(), getVelocity(), getAngle(), 8.0,
		[&ui](const Position& pos, double rot, const Position& offset) { ui.drawHubbleRight(pos, rot, offset); }, 2));
}

