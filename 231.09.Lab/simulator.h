/***********************************************************************
 * Header File:
 *    Simulator
 * Author:
 *    Josh and Garrin
 * Summary:
 *    Has all the objects for the simulator to run.
 ************************************************************************/

#pragma once

#include <vector>
#include "spaceObject.h"
#include "satellite.h"
#include "hubble.h"
#include "earth.h"
#include "starlink.h"
#include "gps.h"
#include "dragon.h"
#include "sputnik.h"
#include "dreamChaser.h"
#include "star.h"

class TestSimulator;

 /*********************************************
  * Simulator
  * Holds all of the objects.
  *********************************************/
class Simulator
{
private:
	vector<SpaceObject*> spaceObjects;
	vector<Star*> stars;
	DreamChaser player;

public:

	friend TestSimulator;

	Simulator();
	vector<SpaceObject*>& getSpaceObjects();
	vector<Star*>& getStars();
	DreamChaser& getPlayer() { return player; }
	void objectCollisions(vector<SpaceObject*>& spaceObjects);

};