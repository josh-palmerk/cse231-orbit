/***********************************************************************
 * Source File:
 *    Earth : The source information for Earth
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the earth
 ************************************************************************/


#include "earth.h"


 /***********************************************
  * EARTH: Default Constructor
  * Creates the earth object
  ***********************************************/
Earth::Earth()
	: SpaceObject(Position(0, 0), Velocity(0, 0), Angle(0), 6378000.0, false) // Earth's radius in meters
{
}

/***********************************************
 * EARTH: Draw
 * Draws the earth
 ***********************************************/
void Earth::draw(ogstream& ui) const
{
	ui.drawEarth(getPosition(), getAngle().getRadians());
}

/***********************************************
 * EARTH: updateObject
 * Overrides updateobject to rotate the earth.
 ***********************************************/
void Earth::updateObject(double timestep, vector<SpaceObject*>& spaceObjects)
{

	// Calculates radians for accurate rotation this frame
	rotate(-(2.0 * M_PI / 86400) * timestep);
}
