/***********************************************************************
 * Header File:
 *    Test Simulator : Test the Simulator class
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for Simulator
 ************************************************************************/

#pragma once

#include "simulator.h"
#include "unitTest.h"
#include <iostream>

 /*******************************
  * TEST Simulator
  * A friend class for Simulator which contains the Simulator unit tests
  ********************************/
class TestSimulator : public UnitTest
{
public:
    void run()
    {
        // Constructors
        defaultConstructor();

        //Collision
        dragonCollideStarlink();
        hubbleCollideEarth();
        dreamChaserCollideGPS();

        report("Simulator");
    }

private:

    void defaultConstructor();
    void dragonCollideStarlink();
    void hubbleCollideEarth();
    void dreamChaserCollideGPS();



};
