/***********************************************************************
 * Header File:
 *    SpaceObject
 * Author:
 *    Josh and Garrin
 * Summary:
 *    Base class for all space objects.
 ************************************************************************/

#pragma once

#include <cassert>
#include <cmath>
#include "velocity.h"
#include "position.h"
#include "angle.h"
#include "uiDraw.h"
#include "acceleration.h"
#include <vector>

class TestSpaceObject;
class TestHubble;
class TestEarth;
class TestDreamChaser;
class TestStar;
class TestSimulator;

class SpaceObject
{

public:

	friend TestSpaceObject;
	friend TestHubble;
	friend TestEarth;
	friend TestDreamChaser;
	friend TestStar;
	friend TestSimulator;

	SpaceObject();
	SpaceObject(const Position& pos, const Velocity& vel, const Angle& angle, double radius, bool dead);
	 
	// Getters
	Position getPosition() const	{ return position; }
	Velocity getVelocity() const	{ return velocity; }
	Angle getAngle() const			{ return angle; }
	double getRadius() const		{ return radius; }
	int getSecondsAlive() const     { return secondsAlive; }
	bool isDead() const				{ return dead; }

	// Setters
	void setPosition(const Position& position)	{ this->position = position; };
	void setVelocity(const Velocity& velocity)	{ this->velocity = velocity; };
	void setAngle(const Angle& angle)			{ this->angle = angle; };
	void setRadius(double radius)				{ this->radius = radius; };
	void setSecondsAlive(int secondsAlive)      { this->secondsAlive = secondsAlive; };

	// Behavior
	void applyGravity(const Position& center, double gravitationalConstant, double timeStep);
	void updatePosition(double timeStep);
	void rotate(double radians);
	virtual void updateObject(double timestep, vector<SpaceObject*> & spaceObjects);
	void incrementSecondsAlive(int amount);
	virtual void draw(ogstream& ui) const = 0;
	virtual void shatter(vector<SpaceObject*>& spaceObjects) {};
	virtual void die() {};

protected:
	Position position;
	Velocity velocity;
	Angle angle;
	int secondsAlive;
	double radius;
	bool dead;
};


/***************************************************
 * SPACE OBJECT DERIVED
 * A simple derived class so we can test Space Object.
 ***************************************************/
class SpaceObjectDerived : public SpaceObject
{
public:
	SpaceObjectDerived() : SpaceObject() {}
	SpaceObjectDerived(const Position& pos, const Velocity& vel, const Angle& angle, double radius, bool dead)
		: SpaceObject(pos, vel, angle, radius, dead) {}
	void draw(ogstream& ui) const  { assert(false && "draw should not be called"); }
};
