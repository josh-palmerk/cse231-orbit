/***********************************************************************
 * Header File:
 *    Part
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Space Junk Part.
 ************************************************************************/

#pragma once
#include "spaceJunk.h"
#include <functional>

enum PartType
{
	GPS_CENTER,
	GPS_LEFT,
	GPS_RIGHT,
	HUBBLE_TELESCOPE,
	HUBBLE_COMPUTER,
	HUBBLE_LEFT,
	HUBBLE_RIGHT,
	DRAGON_CENTER,
	DRAGON_LEFT,
	DRAGON_RIGHT,
	STARLINK_BODY,
	STARLINK_ARRAY

};

class Part : public SpaceJunk
{
public:
	Part();
	Part(const Position& pos, const Velocity& vel, const Angle& angle, double radius, PartType type);
	void draw(ogstream& ui) const override;
	void shatter(vector<SpaceObject*>& spaceObjects);
	void updateObject(double timestep, vector<SpaceObject*>& spaceObjects) override;
private:
	std::function <void(const Position&, double, const Position&)> drawFunction;
	PartType type;
	int fragNum; // number of fragments made when shattered
};
