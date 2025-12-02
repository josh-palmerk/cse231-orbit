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
SpaceJunk::SpaceJunk(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: SpaceObject(pos, vel, angle, radius)
{
}

