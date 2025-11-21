#include "dreamChaser.h"

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

DreamChaser::DreamChaser(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: SpaceObject(pos, vel, angle, radius)
{
}

void DreamChaser::draw(ogstream& ui) const
{
	ui.drawShip(getPosition(), getAngle().getRadians(), false); // TODO bool thrust
}

void DreamChaser::fireBullet()
{
	// Logic for firing a bullet
}

void DreamChaser::addThrust(double timestep)
{
	// Apply thrust in the direction of the current angle
	double thrustMagnitude = 2.0; // Example thrust magnitude
	double ax = thrustMagnitude * cos(getAngle().getRadians());
	double ay = thrustMagnitude * sin(getAngle().getRadians());
	Acceleration acc(ax, ay);
	velocity.add(acc, timestep);
}

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
		angle.add(-0.1 * timestep); // Radians per time step
	}
	if (pUI->isRight())
	{
		// Rotate right
		angle.add(0.1 * timestep); // Radians per time step
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