/***********************************************************************
 * Header File:
 *    Test Earth : Test the Earth class
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for Earth
 ************************************************************************/

#pragma once

#include "earth.h"
#include "unitTest.h"


 /*******************************
  * TEST Earth
  * A friend class for Earth which contains the Earth unit tests
  ********************************/
class TestEarth : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();


        //Behavior
        //updateObject is overridden
        earthUpdateObjectOneSecond();
        earthUpdateObjectFullRotation();
        earthUpdateObjectHalfRotation();

        report("Earth");
    }



private:

    void defaultConstructor();
    void earthUpdateObjectOneSecond();
    void earthUpdateObjectFullRotation();
    void earthUpdateObjectHalfRotation();

};



