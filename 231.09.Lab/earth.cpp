#include "earth.h"

Earth::Earth()
	: SpaceObject(Position(0, 0), Velocity(0, 0), Angle(0), 6378000.0) // Earth's radius in meters
{
}

void Earth::draw(ogstream& ui) const
{
	ui.drawEarth(getPosition(), getAngle().getRadians());
}

void Earth::updateObject(double timestep)
{

	// Calculates radians for accurate rotation this frame
	rotate((2.0 * M_PI / 86400) * timestep);
}
