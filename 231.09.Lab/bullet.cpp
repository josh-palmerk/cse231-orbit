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
	: SpaceObject(Position(0, 0), Velocity(0, 0), Angle(0), 0.5 * 128000.0, false) // Radius in meters
{
}

Bullet::Bullet(Position pos, Velocity vel)
	: SpaceObject()
{
	position = pos;
	velocity = vel;
	radius = 0.5 * 128000.0;
	dead = false;
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
void Bullet::die()
{
	if (secondsAlive >= 2)
	{
		dead = true;
	}
	else
	{
		dead = false;
	}
}