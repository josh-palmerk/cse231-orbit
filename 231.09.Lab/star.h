/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "spaceObject.h" // for SPACEOBJECT
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR

class TestStar;

 /*****************************************************
  * STAR
  * A star that twinkles
  *****************************************************/
class Star : public SpaceObject
{
public:

	friend TestStar;

	Star();
	Star(double width, double height);
	void draw(ogstream& gout) const override;
	void incrementPhase();
	void updateObject(double timestep, vector<SpaceObject*>& spaceObjects) override;

private:
	Position pos;
	unsigned char phase;
};
