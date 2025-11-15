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


class Earth : public SpaceObject
{
public:
	Earth();
	virtual void draw(ogstream& ui) const override;
	virtual void updateObject(double timestep) override;
};

