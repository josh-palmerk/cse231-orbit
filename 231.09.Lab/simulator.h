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
//#include "dreamChaser.h"


 /*********************************************
  * Simulator
  * Holds all of the objects.
  *********************************************/
class Simulator
{
private:
	//to do add stars.
	vector<SpaceObject*> spaceObjects;

public:
	Simulator();
	vector<SpaceObject*> getSpaceObjects();


};