#pragma once
#include "satellite.h"

class TestStarlink;

class Starlink : public Satellite
{
public:
	friend TestStarlink;
	Starlink();
	Starlink(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void draw(ogstream& ui) const override;
	void shatter() override;
};
