#include "part.h"

/***********************************************	
* PART : Default Constructor
* 	   Creates the part object
* **********************************************/

Part::Part()
	: SpaceJunk()
{
}

/***********************************************
* PART : NonDefault Constructor
* 	   Creates a part object
* ***********************************************/

Part::Part(const Position& pos, const Velocity& vel, const Angle& angle, double radius, std::function <void(const Position&, double)> drawFunction)
	: SpaceJunk(pos, vel, angle, radius)
{
	this->drawFunction = drawFunction;
	addKick();
}

/***********************************************
* PART : Draw
* 	   Draws the part object
* ***********************************************/
void Part::draw(ogstream& ui) const
{
	// Drawing logic for Part
	this->drawFunction(getPosition(), getAngle().getRadians());
}