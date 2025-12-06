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

/***********************************
* SIMULATOR: Object Collisions
* Checks to see if any objects have collided.
***********************************/
void Simulator::objectCollisions(vector<SpaceObject*>& spaceObjects)
{
	//make an array to send all crashed objects to
	vector<SpaceObject*> spaceObjectsCrashed;

	//loop through each object to then loop through to check against every other object.
	for (int i = 0; i < spaceObjects.size(); i++)
	{
		for (int x = i + 1; x < spaceObjects.size(); x++)
		{
			double distance = computeDistance(spaceObjects[i]->getPosition(), spaceObjects[x]->getPosition());

			if (spaceObjects[i]->isDead() == false && spaceObjects[x]->isDead() == false)
			{
				if (distance < (spaceObjects[i]->getRadius() + spaceObjects[x]->getRadius()))
				{
					//if they hit have them die
					spaceObjects[i]->die();
					spaceObjects[x]->die();
					//then send them to the crashed vector
					spaceObjectsCrashed.push_back(spaceObjects[i]);
					spaceObjectsCrashed.push_back(spaceObjects[x]);
				}
			}

		}
	}


	//check for collisions with the player
	for (auto obj : spaceObjects)
	{
		double distance = computeDistance(obj->getPosition(), player.getPosition());
		if (player.isDead() == false && obj->isDead() == false)
		{
			if (distance < (player.getRadius() + obj->getRadius()))
			{
				obj->die();
				player.die();
				spaceObjectsCrashed.push_back(obj);
			}
		}
	}

	//erase all crashed objects and add in the parts.
	for (auto obj : spaceObjectsCrashed)
	{
		if (obj->isDead())
		{
			obj->shatter(spaceObjects);

		}
	}

	//get rid of the dead objects (ai generated)
	spaceObjects.erase(
		remove_if(spaceObjects.begin(), spaceObjects.end(),
			[](SpaceObject* obj) { return obj->isDead(); }),
		spaceObjects.end()
	);



}
