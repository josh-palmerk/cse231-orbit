/***********************************************************************
 * Header File:
 *    Starlink
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Satellite space object starlink.
 ************************************************************************/

#pragma once
#include "satellite.h"

class TestStarlink;

class Starlink : public Satellite
{
public:
	friend TestStarlink;
	Starlink();
	Starlink(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void draw(ogstream& ui) const override;
	void shatter(vector<SpaceObject*>& spaceObjects) override;
	void die() override;
};
