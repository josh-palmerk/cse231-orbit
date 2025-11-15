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


    /*****************************************************************
    *****************************************************************
    * CONSTRUCTORS
    *****************************************************************
    *****************************************************************/

    /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  zero
    *********************************************/
    void defaultConstructor()
    {
        // setup
        // exercise
        Earth e;

        // verify
        assertEquals(e.position.x, 0.0);
        assertEquals(e.position.y, 0);
        assertEquals(e.velocity.dx, 0);
        assertEquals(e.velocity.dy, 0.0);
        assertEquals(e.angle.radians, 0.0);
        assertEquals(e.radius, 6378000.0);
        assertEquals(e.secondsAlive, 0);
    }
    // teardown




    /*****************************************************************
    *****************************************************************
    * BEHAVIORS
    *****************************************************************
    *****************************************************************/



    /*********************************************
    * name:    EARTH UPDATE OBJECT ONE SECOND
    * input:   radians = 0, timeStep = 1
    * output:  radians = 6.283112585, timeStep = 1
    *********************************************/
    void earthUpdateObjectOneSecond()
    {
        // setup
        Earth e;
        e.angle.radians = 0;
        double timeStep = 1;

        // exercise
        e.updateObject(timeStep);

        // verify
        assertEquals(e.angle.radians, 6.283112585);
        assertEquals(timeStep, 1);

    }
    // teardown


    /*********************************************
    * name:    EARTH UPDATE OBJECT FULL ROTATION
    * input:   radians = 0, timeStep = 60
    * output:  radians = 6.278822, timeStep = 60
    *********************************************/
    void earthUpdateObjectFullRotation()
    {
        // setup
        Earth e;
        e.angle.radians = 0;
        double timeStep = 60;

        // exercise
        e.updateObject(timeStep);

        // verify
        assertEquals(e.angle.radians, 6.278822);
        assertEquals(timeStep, 60);

    }
    // teardown


    /*********************************************
    * name:    EARTH UPDATE OBJECT HALF ROTATION
    * input:   radians = 0, timeStep = 30
    * output:  radians = 6.2810, timeStep = 30
    *********************************************/
    void earthUpdateObjectHalfRotation()
    {
        // setup
        Earth e;
        e.angle.radians = 0;
        double timeStep = 30;

        // exercise
        e.updateObject(timeStep);

        // verify
        assertEquals(e.angle.radians, 6.2810);
        assertEquals(timeStep, 30);

    }
    // teardown

};



