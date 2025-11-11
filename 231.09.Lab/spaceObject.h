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
	Position getPosition() const;
	Velocity getVelocity() const;
	Angle getAngle() const;
	double getRadius() const;

	// Setters
	void setPosition(const Position& position);
	void setVelocity(const Velocity& velocity);
	void setAngle(const Angle& angle);
	void setRadius(double radius);

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
