#include "part.h"
#include "fragment.h"

/***********************************************	
* PART : Default Constructor
* 	   Creates the part object
* **********************************************/

Part::Part()
	: SpaceJunk()
{
	fragNum = 2;
}

/***********************************************
* PART : NonDefault Constructor
* 	   Creates a part object
* ***********************************************/

Part::Part(const Position& pos, const Velocity& vel, const Angle& angle, double radius, std::function <void(const Position&, double, const Position&)> drawFunction, int fragNum)
	: SpaceJunk(pos, vel, angle, radius, dead)
{
	this->drawFunction = drawFunction;
	this->fragNum = fragNum;
	addKick();
}

/***********************************************
* PART : Draw
* 	   Draws the part object
* ***********************************************/
void Part::draw(ogstream& ui) const
{
	// Drawing logic for Part
	drawFunction(getPosition(), getAngle().getRadians(), Position());
}

/***********************************************
* PART : Shatter
* 	   Shatters part into fragments.
************************************************/
void Part::shatter(vector<SpaceObject*>& spaceObjects)
{
	// Logic for Part shattering
	for (int i = 0; i < fragNum; ++i)
	{
		spaceObjects.push_back(new Fragment(getPosition(), getVelocity(), getAngle(), 2.0, false));
	}
}