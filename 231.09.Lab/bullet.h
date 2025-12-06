/***********************************************************************
 * Header File:
 *    Bullet
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Space object bullet.
 ************************************************************************/

#pragma once
#include "spaceObject.h"

class TestBullet;

class Bullet : public SpaceObject
{
public:
	friend TestBullet;
	Bullet();
	Bullet(Position pos, Velocity vel, Angle ang);
	void die() override;
	virtual void draw(ogstream& ui) const override;
	virtual void updateObject(double timestep, vector<SpaceObject*>& spaceObjects) override;
};
