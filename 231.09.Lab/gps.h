/***********************************************************************
 * Header File:
 *    GPS
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Satellite space object GPS.
 ************************************************************************/

#pragma once
#include "satellite.h"

class TestGPS;

class GPS : public Satellite
{
public:
	friend TestGPS;

	GPS();
	GPS(const Position& pos, const Velocity& vel, const Angle& angle = Angle(0.0), double radius = 12 * 128000);
	void draw(ogstream& ui) const override;
	void shatter(vector<SpaceObject*>& spaceObjects) override;
};

