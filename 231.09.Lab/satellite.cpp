#include "satellite.h"
Satellite::Satellite()
	: SpaceObject(), defunct(false)
{
}

Satellite::Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: SpaceObject(pos, vel, angle, radius), defunct(false)
{
}

