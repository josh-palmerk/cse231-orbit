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
	spaceObjects.push_back(new Earth());
	spaceObjects.push_back(new Starlink());

	spaceObjects.push_back(new GPS(Position(0.0, 26560000.0),			Velocity(-3880.0, 0.0)) );
	spaceObjects.push_back(new GPS(Position(23001634.72, 13280000.0),	Velocity(-1940.00, 3360.18)));
	spaceObjects.push_back(new GPS(Position(23001634.72, -13280000.0),	Velocity(1940.00, 3360.18)));
	spaceObjects.push_back(new GPS(Position(0.0, -26560000.0),			Velocity(3880.0, 0.0)));
	spaceObjects.push_back(new GPS(Position(-23001634.72, -13280000.0),	Velocity(1940.00, -3360.18)));
	spaceObjects.push_back(new GPS(Position(-23001634.72, 13280000.0),	Velocity(-1940.00, -3360.18)));

	spaceObjects.push_back(new Dragon());
	spaceObjects.push_back(new Sputnik());


	// Initialize 50 stars at random positions
	for (int i = 0; i < 50; i++)
	{
		spaceObjects.push_back(new Star(500, 500));
	}
}

/************************************************
 * SIMULATOR : GET SPACE OBJECTS
 * Returns spaceObjects.
 ***********************************************/
vector<SpaceObject*>& Simulator::getSpaceObjects()
{
	return spaceObjects;
}
