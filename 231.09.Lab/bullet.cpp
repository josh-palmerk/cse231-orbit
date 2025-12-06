/***********************************************************************
 * Source File:
 *    Bullet : The source information for Bullet
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of bullet
 ************************************************************************/


#include "bullet.h"


 /***********************************************
  * BULLET: Default Constructor
  * Creates the earth object
  ***********************************************/
Bullet::Bullet()
	: SpaceObject(Position(0, 0), Velocity(0, 0), Angle(0), 0.5) // Radius in pixels?
{
}

Bullet::Bullet(Position pos, Velocity vel)
	: SpaceObject()
{
	position = pos;
	velocity = vel;
	radius = 1.5;
}

/***********************************************
 * BULLET: Draw
 * Draws the bullet
 ***********************************************/
void Bullet::draw(ogstream& ui) const
{
	ui.drawProjectile(getPosition());
}

/***********************************************
 * BULLET: updateObject
 * Overrides updateobject to move the bullet.
 ***********************************************/
void Bullet::updateObject(double timestep, vector<SpaceObject*>& spaceObjects)
{
	//same as spaceobject but doesnt apply gravity.
	updatePosition(timestep);
	incrementSecondsAlive(static_cast<int>(timestep));
}

/***********************************************
 * BULLET: isExpired
 * The bullet expires after 2 seconds.
 ***********************************************/
bool Bullet::isExpired()
{
	if (secondsAlive >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}