#pragma once
#include "satellite.h"

class Hubble : public Satellite
{
public:
	Hubble();
	Hubble(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void draw(ogstream& ui) const override;
	void shatter() override;
};


Hubble::Hubble()
	: Satellite()
{
	Position pos(0.0, -42164000.0);
	Velocity vel(3100.0, 0.0);
	Angle angle(0.0);
	setPosition(pos);
	setVelocity(vel);
	setAngle(angle);
}


Hubble::Hubble(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: Satellite(pos, vel, angle, radius)
{
}


void Hubble::draw(ogstream& ui) const
{
	// Drawing logic for Hubble telescope
	ui.drawHubble(getPosition(), getAngle().getRadians());
}


void Hubble::shatter()
{
	// Logic for Hubble shattering
}