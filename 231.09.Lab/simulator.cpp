/***********************************************************************
 * Source File:
 *    Simulator : The driving source for the program
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Contains callback and all of the objects.
 ************************************************************************/

#include "simulator.h"

 /***********************************************
 * SIMULATOR : Default Constructor
 *         Create all objects
 ***********************************************/
Simulator::Simulator()
{
	spaceObjects.push_back(new Hubble());
}

/************************************************
 * SIMULATOR : GET SPACE OBJECTS
 * Returns spaceObjects.
 ***********************************************/
vector<SpaceObject*> Simulator::getSpaceObjects()
{
	return spaceObjects;
}
