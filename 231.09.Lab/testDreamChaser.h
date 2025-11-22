/***********************************************************************
 * Header File:
 *    TEST DREAMCHASER
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for Dream Chaser
 ************************************************************************/

#pragma once


#include "dreamChaser.h"
#include "unitTest.h"


 /*******************************
  * TEST Dream Chaser
  * A friend class for Dream Chaser which contains the Dream Chaser unit tests
  ********************************/
class TestDreamChaser : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();

        //Input
        //turning
        turnLeftFromZero();
        turnLeftFromPositive();
        turnLeftFromNegative();
        turnRightFromZero();
        turnRightFromPositive();
        turnRightFromNegative();
        //thrusters
        thrusterTurnsOn();
        addThrustPositiveAngle();
        addThrustNegativeAngle();
        addThrustDifferentTimeStep();
        addThrustToExistingVelocity();

        report("Dream Chaser");
    }



private:

    void defaultConstructor();
    void nonDefaultConstructor();
    void turnLeftFromZero();
    void turnLeftFromPositive();
    void turnLeftFromNegative();
    void turnRightFromZero();
    void turnRightFromPositive();
    void turnRightFromNegative();
    void thrusterTurnsOn();
    void addThrustPositiveAngle();
    void addThrustNegativeAngle();
    void addThrustDifferentTimeStep();
    void addThrustToExistingVelocity();


   
};
