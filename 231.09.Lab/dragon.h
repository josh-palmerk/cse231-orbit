/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Satellite space object dragon.
 ************************************************************************/

#pragma once

#include "satellite.h"

class TestDragon;

class Dragon : public Satellite
{
public:
	friend TestDragon;
	Dragon();
	Dragon(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void draw(ogstream& ui) const override;
	void shatter(vector<SpaceObject*>& spaceObjects) override;
	void die() override;
};
