/***********************************************************************
 * Source File:
 *    Space Junk : The base class for space junk
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The base class for space junk
 ************************************************************************/

#include "spaceJunk.h"

/***********************************************
* SPACE JUNK : Default Constructor
*         Creates the space junk object
***********************************************/
SpaceJunk::SpaceJunk()
	: SpaceObject()
{
}

/***********************************************
* SPACE JUNK : NonDefault Constructor
*         Creates a space junk object
* ***********************************************/
SpaceJunk::SpaceJunk(const Position& pos, const Velocity& vel, const Angle& angle, double radius, bool dead)
	: SpaceObject(pos, vel, angle, radius, dead)
{
}

/***********************************************
* SPACE JUNK : Add Kick
*         Adds a kick to the space junk object
* **********************************************/
void SpaceJunk::addKick()
{
	double newSpeed = this->getVelocity().getSpeed() + random(5000, 9000);
	
	Acceleration kick(0, 0); 
	Angle newAngle = Angle(random(0, 360));
	kick.set(newAngle, newSpeed);

	Velocity currentVelocity = getVelocity();
	currentVelocity.add(kick, 1); // Assuming a time step of 1 second for the kick
	setVelocity(currentVelocity);
	updatePosition(48); // Update position immediately after the kick
}

/***********************************************
* SPACE JUNK : Update Object
*         Updates the space junk object
* ***********************************************/

void SpaceJunk::updateObject(double timestep, vector<SpaceObject*>& spaceObjects)
{
	//// Call the base class updateObject to handle position update
	//SpaceObject::updateObject(timestep, spaceObjects);
	//// Additional logic for SpaceJunk can be added here if needed
	applyGravity(Position(0, 0), 398600441800000.0, timestep); // Example gravitational constant for Earth)
	updatePosition(timestep);
	incrementSecondsAlive(static_cast<int>(timestep));
}