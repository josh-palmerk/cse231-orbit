/***********************************************************************
 * Source File:
 *    Dream Chaser : The source information for the Dream Chaser space object
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The declarations of the Dream Chaser space object.
 ************************************************************************/

#include "dreamChaser.h"


 /***********************************************
 * DREAM CHASER: Default Constructor
 *               Creates the Dream Chaser object
 ***********************************************/
DreamChaser::DreamChaser()
	: SpaceObject()
{
	Position pos(40000000.0, 40000000.0); // Approximate altitude of Dream Chaser
	Velocity vel(0.0, -2000.0);     // Approximate orbital velocity
	Angle angle(0.0);
	setPosition(pos);
	setVelocity(vel);
	setAngle(angle);
	setRadius(10); // radius of Dream Chaser in pixels
}


/***********************************************
 * DREAMCHASER: NonDefault Constructor
 *              Creates a Dream Chaser object
 ***********************************************/
DreamChaser::DreamChaser(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: SpaceObject(pos, vel, angle, radius)
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
void DreamChaser::fireBullet()
{
	// Logic for firing a bullet
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
void DreamChaser::handleInput(const Interface* pUI, double timestep)
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
		fireBullet();
	}
}




//void DreamChaser::updateObject(double timestep) 
//{
//
//	applyGravity(Position(0, 0), 398600441800000.0, timestep); // Example gravitational constant for Earth)
//	updatePosition(timestep);
//	incrementSecondsAlive(static_cast<int>(timestep));
//
//	// TODO need to handle thrust effects here
//}