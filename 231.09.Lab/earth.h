#pragma once
#include "spaceObject.h"


class Earth : public SpaceObject
{
public:
	Earth();
	//Earth(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	virtual void draw(ogstream& ui) const override;
	virtual void updateObject(double timestep) override;
};

