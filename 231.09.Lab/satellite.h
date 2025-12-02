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
#include "fragment.h"
#include "part.h"
#include "uiDraw.h"

class Satellite : public SpaceObject
{
public:
	Satellite();
	Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	//void draw() const override;

	bool isDefunct() const { return defunct; }
	void updateObject(double timestep, vector<SpaceObject*>& spaceObjects) override;

	virtual void shatter(vector<SpaceObject*>& spaceObjects) = 0;

protected:
	bool defunct;
};
