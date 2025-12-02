/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Space junk base class.
 ************************************************************************/

#pragma once
#include "spaceObject.h"


class SpaceJunk : public SpaceObject
{
public:
	SpaceJunk();
	SpaceJunk(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void addKick();
	void updateObject(double timestep, vector<SpaceObject*>& spaceObjects) override;
};
