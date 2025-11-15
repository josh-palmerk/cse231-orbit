#pragma once
#include "spaceObject.h"


class Earth : public SpaceObject
{
public:
	Earth();
	//Earth(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	virtual void draw(ogstream& ui) const override;
	virtual void updateObject(double timestep);
};

Earth::Earth()
	: SpaceObject(Position(0, 0), Velocity(0, 0), Angle(0), 6378000.0) // Earth's radius in meters
{
}

void Earth::draw(ogstream& ui) const
{
	ui.drawEarth(getPosition(), getRadius());
}

void Earth::updateObject(double timestep) 
{

	// Calculates radians for accurate rotation this frame
	rotate((2.0 * M_PI / 86400) * timestep);
}
