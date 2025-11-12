#pragma once
#include "spaceObject.h"
class Satellite : public SpaceObject
{
public:
	Satellite();
	Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double radius);
	//void draw() const override;

	bool isDefunct() const { return defunct; }

	virtual void shatter() = 0;

private:
	bool defunct;
};
