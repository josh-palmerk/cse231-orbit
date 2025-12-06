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
	Acceleration kick(random(5000.0, 9000.0), random(5000.0, 9000.0)); 
	// pretty sure it's 5000-9000 total, not each. might need to use set() for this
	Velocity currentVelocity = getVelocity();
	currentVelocity.add(kick, 1.0); // Assuming a time step of 1 second for the kick
	setVelocity(currentVelocity);
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
	
}