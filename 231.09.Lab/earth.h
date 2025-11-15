/***********************************************************************
 * Header File:
 *    Earth
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Space object earth.
 ************************************************************************/

#pragma once
#include "spaceObject.h"

class TestEarth;

class Earth : public SpaceObject
{
public:
	friend TestEarth;
	Earth();
	virtual void draw(ogstream& ui) const override;
	virtual void updateObject(double timestep) override;
};

