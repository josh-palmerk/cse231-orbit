#pragma once
#include "satellite.h"
class Hubble : public Satellite
{
public:
	Hubble();
	Hubble(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void draw() const override;
	void shatter() override;
};


Hubble::Hubble()
	: Satellite()
{
}
Hubble::Hubble(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: Satellite(pos, vel, angle, radius)
{
}
void Hubble::draw() const
{
	// Drawing logic for Hubble telescope
}

void Hubble::shatter()
{
	// Logic for Hubble shattering
}