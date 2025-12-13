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

Part::Part(const Position& pos, const Velocity& vel, const Angle& angle, double radius, PartType type)
	: SpaceJunk(pos, vel, angle, radius, dead)
{
	//this->drawFunction = drawFunction;
	this->type = type;
	this->dead = false;
	this->fragNum = fragNum;
	addKick();
	updatePosition(48.0); // Move part slightly to avoid immediate collision
}

/***********************************************
* PART : Draw
* 	   Draws the part object
* ***********************************************/
void Part::draw(ogstream& ui) const
{
	// Drawing logic for Part
	//drawFunction(getPosition(), getAngle().getRadians(), Position());
	switch (type)
	{
	case GPS_CENTER:
		ui.drawGPSCenter(getPosition(), getAngle().getRadians());
		break;
	case GPS_LEFT:
		ui.drawGPSLeft(getPosition(), getAngle().getRadians());
		break;
	case GPS_RIGHT:
		ui.drawGPSRight(getPosition(), getAngle().getRadians());
		break;
	case HUBBLE_TELESCOPE:
		ui.drawHubbleTelescope(getPosition(), getAngle().getRadians());
		break;
	case HUBBLE_COMPUTER:
		ui.drawHubbleComputer(getPosition(), getAngle().getRadians());
		break;
	case HUBBLE_LEFT:
		ui.drawHubbleLeft(getPosition(), getAngle().getRadians());
		break;
	case HUBBLE_RIGHT:
		ui.drawHubbleRight(getPosition(), getAngle().getRadians());
		break;
	case DRAGON_CENTER:
		ui.drawCrewDragonCenter(getPosition(), getAngle().getRadians());
		break;
	case DRAGON_LEFT:
		ui.drawCrewDragonLeft(getPosition(), getAngle().getRadians());
		break;
	case DRAGON_RIGHT:
		ui.drawCrewDragonRight(getPosition(), getAngle().getRadians());
		break;
	case STARLINK_BODY:
		ui.drawStarlinkBody(getPosition(), getAngle().getRadians());
		break;
	case STARLINK_ARRAY:
		ui.drawStarlinkArray(getPosition(), getAngle().getRadians());
		break;
	default:
		break;
	}
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