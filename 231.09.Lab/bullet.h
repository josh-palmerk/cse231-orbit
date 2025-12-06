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

/*********************************************
 * Bullet
 * Projectile fired from Dream Chaser
 *********************************************/
class Bullet : public SpaceObject
{
public:

	friend TestBullet;

	Bullet();
	Bullet(Position pos, Velocity vel);
	void die() override;
	virtual void draw(ogstream& ui) const override;
	virtual void updateObject(double timestep, vector<SpaceObject*>& spaceObjects) override;
};
