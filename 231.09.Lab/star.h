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

 /*****************************************************
  * STAR
  * A star that twinkles
  *****************************************************/
class Star : public SpaceObject
{
public:
	Star() {
		phase = 0;
	}

	Star(double width, double height)
	{
		pos.setPixelsX(random(-width, width));
		pos.setPixelsY(random(-height, height));
		phase = random(0, 255); // randomize twinkle phase
	};
	void draw(ogstream& gout) const override
	{
		gout.drawStar(pos, phase);
	};
	void incrementPhase() 
	{
		phase++; // Increment phase and wrap around at 256
	}
	void updateObject(double timestep, vector<SpaceObject*>& spaceObjects) override
	{
		incrementPhase();
	}
private:
	Position pos;
	unsigned char phase;
};
