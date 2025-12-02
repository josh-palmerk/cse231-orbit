#pragma once

#include "spaceJunk.h"

class Fragment : public SpaceJunk
{
public:
	Fragment();
	Fragment(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void draw(ogstream& ui) const override;
	void updateObject(double timestep, vector<SpaceObject*>& spaceObjects) override;
};