/***********************************************************************
 * Source File:
 *    Satellite : The base class for all satellites
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The base class for all satellite objects, inherits space object.
 ************************************************************************/

#include "satellite.h"


 /***********************************************
 * SATTELITE: Default Constructor
 * Create a satellite object
 ***********************************************/
Satellite::Satellite()
	: SpaceObject(), defunct(false)
{
}


/***********************************************
* SATTELITE: NonDefault Constructor
* Create a satellite object with parameters.
***********************************************/
Satellite::Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: SpaceObject(pos, vel, angle, radius), defunct(false)
{
}

