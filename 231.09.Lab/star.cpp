/***********************************************************************
 * Source File:
 *    Star : The source information for the background stars
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the stars.
 ************************************************************************/

#include "star.h"


 /***********************************************
 * STAR: Default Constructor
 *       Creates the star object
 ***********************************************/
Star::Star()
{
	phase = 0;
}

/***********************************************
* STAR: Non Default Constructor
*       Creates the star object
***********************************************/
Star::Star(double width, double height)
{
	pos.setPixelsX(random(-width, width));
	pos.setPixelsY(random(-height, height));
	phase = random(0, 255); // randomize twinkle phase
}

/***********************************************
* STAR: Draw
*       draws the star
***********************************************/
void Star::draw(ogstream& gout) const
{
	gout.drawStar(pos, phase);
}

/***********************************************
* STAR: Increment Phase
*       Adds one to the phase
***********************************************/
void Star::incrementPhase()
{
	phase++; // Increment phase and wrap around at 256
}

/***********************************************
* STAR: Update Object
*       Calls Incrememnt Phase
***********************************************/
void Star::updateObject(double timestep, vector<SpaceObject*>& spaceObjects)
{
	incrementPhase();
}