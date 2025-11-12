#pragma once


#include "velocity.h"
#include "position.h"
#include "angle.h"


class SpaceObject
{
public:
	SpaceObject();
	SpaceObject(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	 
	// Getters
	Position getPosition() const	{ return position; }
	Velocity getVelocity() const	{ return velocity; }
	Angle getAngle() const			{ return angle; }
	double getRadius() const		{ return radius; }

	// Setters
	void setPosition(const Position& position)	{ this->position = position; };
	void setVelocity(const Velocity& velocity)	{ this->velocity = velocity; };
	void setAngle(const Angle& angle)			{ this->angle = angle; };
	void setRadius(double radius)				{ this->radius = radius; };

	// Behavior
	void applyGravity(const Position& center, double gravitationalConstant, double timeStep);
	void updatePosition(double timeStep);
	void rotate(double radians);
	void updateObject();
	void incrementSecondsAlive();
	virtual void draw() const = 0;

private:
	Position position;
	Velocity velocity;
	Angle angle;
	int secondsAlive;
	double radius;
};
