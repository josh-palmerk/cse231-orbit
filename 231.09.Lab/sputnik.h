/***********************************************************************
 * Header File:
 *    Sputnik
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Satellite space object sputnik.
 ************************************************************************/

#pragma once
#include "satellite.h"

class TestSputnik;

class Sputnik : public Satellite
{
public:
	friend TestSputnik;
	Sputnik();
	Sputnik(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	void draw(ogstream& ui) const override;
	void shatter() override;
};