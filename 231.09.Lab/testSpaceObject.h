/***********************************************************************
 * Header File:
 *    Test Space Object : Test the Space Object class
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for Space Object
 ************************************************************************/

#pragma once

#include "spaceObject.h"
#include "unitTest.h"
#include <iostream>

 /*******************************
  * TEST SpaceObject
  * A friend class for Space Object which contains the Space Object unit tests
  ********************************/
class TestSpaceObject : public UnitTest
{
public:
    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();

        // Getters
        getPosition();
        getVelocity();
        getAngle();
        getRadius();
        getSecondsAlive();

        // Setters
        setPosition();
        setVelocity();
        setAngle();
        setRadius();
        setSecondsAlive();

        //Behaviors
        updatePositionNoMovement();
        updatePositionTwoAndHalfSeconds();
        rotatePositive();
        rotateNegative();
        rotateNothing();
        applyGravityEarth();
        applyGravityDifferentGravity();
        applyGravityDifferentCenter();
        applyGravityDifferentTimeStep();
        incrementSecondsAlive();
        decrementSecondsAlive();
        updateObjectOneSecond();
        updateObjectFiveSeconds();

        report("Space Object");
    }

private:

    void defaultConstructor();
    void nonDefaultConstructor();
    void getPosition();
    void getVelocity();
    void getAngle();
    void getRadius();
    void getSecondsAlive();
    void setPosition();
    void setVelocity();
    void setAngle();
    void setRadius();
    void setSecondsAlive();
    void updatePositionNoMovement();
    void updatePositionTwoAndHalfSeconds();
    void rotatePositive();
    void rotateNegative();
    void rotateNothing();
    void applyGravityEarth();
    void applyGravityDifferentGravity();
    void applyGravityDifferentCenter();
    void applyGravityDifferentTimeStep();
    void incrementSecondsAlive();
    void decrementSecondsAlive();
    void updateObjectOneSecond();
    void updateObjectFiveSeconds();


};