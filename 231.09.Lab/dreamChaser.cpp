/***********************************************************************
 * Source File:
 *    Dream Chaser : The source information for the Dream Chaser space object
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the Dream Chaser space object.
 ************************************************************************/

#include "dreamChaser.h"
#include "bullet.h"
#include <cmath>


 /***********************************************
 * DREAM CHASER: Default Constructor
 *               Creates the Dream Chaser object
 ***********************************************/
DreamChaser::DreamChaser()
	: SpaceObject()
{
	Position pos(40000000.0, 40000000.0); // Approximate altitude of Dream Chaser
	Velocity vel(0.0, -2000.0);     // Approximate orbital velocity
	Angle angle(0);
	setPosition(pos);
	setVelocity(vel);
	setAngle(angle);
	setRadius(10 * 128000.0); // radius of Dream Chaser in pixels
}


/***********************************************
 * DREAMCHASER: NonDefault Constructor
 *              Creates a Dream Chaser object
 ***********************************************/
DreamChaser::DreamChaser(const Position& pos, const Velocity& vel, const Angle& angle, double radius, bool dead)
	: SpaceObject(pos, vel, angle, radius, dead)
{
}


/***********************************************
* DREAMCHASER: Draw
*              Draws the Dream Chaser space object
***********************************************/
void DreamChaser::draw(ogstream& ui, const Interface* pUI) const
{
	ui.drawShip(getPosition(), getAngle().getRadians(), pUI->isDown());
}



/***********************************************
* DREAMCHASER: Fire Bullet
*              Fires a bullet from the Dream Chaser
***********************************************/
void DreamChaser::fireBullet(vector<SpaceObject*>& bullets)
{

	// amount to offset
	double dy = 19.0 * 128000;

	// Rotate the offset to the ship's current orientation, generated with ai
	double frontX = getPosition().getMetersX() + dy * sin(getAngle().getRadians());
	double frontY = getPosition().getMetersY() + dy * cos(getAngle().getRadians());

	Position front(frontX, frontY);

	// Logic for firing a bullet
	Position p = front;
	Velocity v;
	v.set(getAngle(), 9000);
	bullets.push_back(new Bullet(p, v));
}


/***********************************************
* DREAMCHASER: Add Thrust
*              Adds thrust to the Dream Chaser
***********************************************/
void DreamChaser::addThrust(double timestep)
{
	// Apply thrust in the direction of the current angle
	double thrustMagnitude = 2.0; // Example thrust magnitude
	double ax = thrustMagnitude * sin(getAngle().getRadians());
	double ay = thrustMagnitude * cos(getAngle().getRadians());
	Acceleration acc(ax, ay);
	velocity.add(acc, timestep);
}


/***********************************************
* DREAMCHASER: Handle Input
*              Allows the user to add thrust and
*              rotate the Dream Chaser
***********************************************/
void DreamChaser::handleInput(const Interface* pUI, double timestep, vector<SpaceObject*>& bullets)
{
	if (pUI->isDown())
	{
		// Thrust forward
		addThrust(timestep);
	}
	if (pUI->isLeft())
	{
		// Rotate left
		angle.add(-0.1); // Radians per time step
	}
	if (pUI->isRight())
	{
		// Rotate right
		angle.add(0.1); // Radians per time step
	}

	if (pUI->isSpace())
	{
		fireBullet(bullets);
	}
}