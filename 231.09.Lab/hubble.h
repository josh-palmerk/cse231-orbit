/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Satellite space object hubble.
 ************************************************************************/


#pragma once
#include "satellite.h"

class TestHubble;

class Hubble : public Satellite
{
public:
	friend TestHubble;

	Hubble();
	Hubble(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void draw(ogstream& ui) const override;
	void shatter(vector<SpaceObject*>& spaceObjects) override;
	void die() override;
};


