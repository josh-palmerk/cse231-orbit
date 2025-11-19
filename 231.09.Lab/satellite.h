/***********************************************************************
 * Header File:
 *    Satellite
 * Author:
 *    Josh and Garrin
 * Summary:
 *    A space object satellite class.
 ************************************************************************/


#pragma once
#include "spaceObject.h"


class Satellite : public SpaceObject
{
public:
	Satellite();
	Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	//void draw() const override;

	bool isDefunct() const { return defunct; }
	void updateObject(double timestep) override;

	virtual void shatter() = 0;

protected:
	bool defunct;
};
