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
        updateObjectHalfSecond();

        report("Space Object");
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
        SpaceObjectDerived so;

        // verify
        assertEquals(so.position.x, 0.0);
        assertEquals(so.position.y, 0.0);
        assertEquals(so.velocity.dx, 0.0);
        assertEquals(so.velocity.dy, 0.0);
        assertEquals(so.angle.radians, 0.0);
        assertEquals(so.radius, 0.0);
        assertEquals(so.secondsAlive, 0);
    }  
    // teardown



    /*********************************************
     * name:    NON DEFAULT CONSTRUCTOR
     * input:   pos(1.3, 1.5) velocity(2.3, 4.5)
     *          angle(0.8) radius = 8.6
     * output:  pos(1.3, 1.5) velocity(2.3, 4.5)
     *          angle(0.8) radius = 8.6, secondsAlive = 0
     *********************************************/
    void nonDefaultConstructor()
    {  
        // setup
        Position pos;
        pos.x = 1.3;
        pos.y = 1.5;
        Velocity v;
        v.dx = 2.3;
        v.dy = 4.5;
        Angle ang;
        ang.radians = 0.8;
        double radius = 8.6;

        // exercise
        SpaceObjectDerived so(pos, v, ang, radius);

        // verify
        assertEquals(so.position.x, 1.3);
        assertEquals(so.position.y, 1.5);
        assertEquals(so.velocity.dx, 2.3);
        assertEquals(so.velocity.dy, 4.5);
        assertEquals(so.angle.radians, 0.8);
        assertEquals(so.radius, 8.6);
        assertEquals(so.secondsAlive, 0);
    }  
    // teardown



    /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
    * name:    GET POSITION
    * input:   (2.35, 4.57)
    * output:  2.35, 4.57
    *********************************************/
    void getPosition()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 2.35;
        so.position.y = 4.57;
        Position pos;

        // exercise
        pos = so.getPosition();

        // verify
        assertEquals(pos.x, 2.35);
        assertEquals(pos.y, 4.57);

    }  
        // teardown


    /*********************************************
    * name:    GET VELOCITY
    * input:   (8.24, 9.63)
    * output:  8.24, 9.63
    *********************************************/
    void getVelocity()
    {
        // setup
        SpaceObjectDerived so;
        so.velocity.dx = 8.24;
        so.velocity.dy = 9.63;
        Velocity v;

        // exercise
        v = so.getVelocity();

        // verify
        assertEquals(v.dx, 8.24);
        assertEquals(v.dy, 9.63);

    }
    // teardown


    /*********************************************
    * name:    GET ANGLE
    * input:   0.428
    * output:  0.428
    *********************************************/
    void getAngle()
    {
        // setup
        SpaceObjectDerived so;
        so.angle.radians = 0.428;
        Angle ang;

        // exercise
        ang = so.getAngle();

        // verify
        assertEquals(ang.radians, 0.428);

    }
    // teardown


    /*********************************************
    * name:    GET RADIUS
    * input:   12.3
    * output:  12.3
    *********************************************/
    void getRadius()
    {
        // setup
        SpaceObjectDerived so;
        so.radius = 12.3;
        double radius = 5.4;

        // exercise
        radius = so.getRadius();

        // verify
        assertEquals(radius, 12.3);

    }
    // teardown


    /*********************************************
    * name:    GET SECONDS ALIVE
    * input:   16
    * output:  16
    *********************************************/
    void getSecondsAlive()
    {
        // setup
        SpaceObjectDerived so;
        so.secondsAlive = 16;
        int secondsAlive = 7;

        // exercise
        secondsAlive = so.getSecondsAlive();

        // verify
        assertEquals(secondsAlive, 16);

    }
    // teardown




    /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
    * name:    SET POSITION
    * input:   (22.22, 33.33), (54.56, 23.78)
    * output:  (54.56, 23.78)
    *********************************************/
    void setPosition()
    {  
        // setup
        SpaceObjectDerived so;
        so.position.x = 22.22;
        so.position.y = 33.33;
        Position pos;
        pos.x = 54.56;
        pos.y = 23.78;

        // exercise
        so.setPosition(pos);

        // verify
        assertEquals(so.position.x, 54.56);
        assertEquals(so.position.y, 23.78);
        assertEquals(pos.x, 54.56);
        assertEquals(pos.y, 23.78);

    }  
    // teardown


    /*********************************************
    * name:    SET VELOCITY
    * input:   (10.15, 20.25), (28.73, 67.29)
    * output:  (28.73, 67.29)
    *********************************************/
    void setVelocity()
    {
        // setup
        SpaceObjectDerived so;
        so.velocity.dx = 10.15;
        so.velocity.dy = 20.25;
        Velocity v;
        v.dx = 28.73;
        v.dy = 67.29;

        // exercise
        so.setVelocity(v);

        // verify
        assertEquals(so.velocity.dx, 28.73);
        assertEquals(so.velocity.dy, 67.29);
        assertEquals(v.dx, 28.73);
        assertEquals(v.dy, 67.29);

    }
    // teardown


    /*********************************************
    * name:    SET ANGLE
    * input:   83.24, 49.83
    * output:  49.83
    *********************************************/
    void setAngle()
    {
        // setup
        SpaceObjectDerived so;
        so.angle.radians = 83.24;
        Angle ang;
        ang.radians = 49.83;

        // exercise
        so.setAngle(ang);

        // verify
        assertEquals(so.angle.radians, 49.83);
        assertEquals(ang.radians, 49.83);

    }
    // teardown


    /*********************************************
    * name:    SET RADIUS
    * input:   48.62, 74.29
    * output:  74.29
    *********************************************/
    void setRadius()
    {
        // setup
        SpaceObjectDerived so;
        so.radius = 48.62;
        double radius;
        radius = 74.29;

        // exercise
        so.setRadius(radius);

        // verify
        assertEquals(so.radius, 74.29);
        assertEquals(radius, 74.29);

    }
    // teardown


    /*********************************************
    * name:    SET SECONDS ALIVE
    * input:   6, 13
    * output:  13
    *********************************************/
    void setSecondsAlive()
    {
        // setup
        SpaceObjectDerived so;
        so.secondsAlive = 6;
        int secondsAlive;
        secondsAlive = 13;

        // exercise
        so.setSecondsAlive(secondsAlive);

        // verify
        assertEquals(so.secondsAlive, 13);
        assertEquals(secondsAlive, 13);

    }
    // teardown





    /*****************************************************************
    *****************************************************************
    * BEHAVIORS
    *****************************************************************
    *****************************************************************/
    
    
    /*********************************************
    * name:    APPLY GRAVITY EARTH
    * input:   Center(0,0) Position(1000000,1000000) 
    *          Gravity = 398600441800000.0
    *          timeStep = 1
    * output:  velocity(-140.9265376903669, -140.9265376903669)
    *********************************************/
    void applyGravityEarth()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 1000000;
        so.position.y = 1000000;
        Position center;
        center.x = 0;
        center.y = 0;
        double gravity = 398600441800000.0;
        double timeStep = 1;

        // exercise
        so.applyGravity(center, gravity, timeStep);

        // verify
        assertEquals(so.velocity.dx, -140.9265376903669);
        assertEquals(so.velocity.dy, -140.9265376903669); 

    }
    // teardown


    /*********************************************
    * name:    APPLY GRAVITY DIFFERENT GRAVITY
    * input:   Center(0,0) Position(1000000,1000000) 
    *          Gravity = 42828370000000.0
    *          timeStep = 1
    * output:  velocity(-15.14211542708325, -15.14211542708325)
    *********************************************/
    void applyGravityDifferentGravity()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 1000000;
        so.position.y = 1000000;
        Position center;
        center.x = 0;
        center.y = 0;
        double gravity = 42828370000000.0;
        double timeStep = 1;

        // exercise
        so.applyGravity(center, gravity, timeStep);

        // verify
        assertEquals(so.velocity.dx, -15.14211542708325);
        assertEquals(so.velocity.dy, -15.14211542708325);

    }
    // teardown


    /*********************************************
    * name:    APPLY GRAVITY DIFFERENT CENTER
    * input:   Center(500000,500000) Position(1000000,1000000) 
    *          Gravity = 398600441800000.0
    *          timeStep = 1
    * output:  velocity(-563.7061507614676, -563.7061507614676)
    *********************************************/
    void applyGravityDifferentCenter()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 1000000;
        so.position.y = 1000000;
        Position center;
        center.x = 500000;
        center.y = 500000;
        double gravity = 398600441800000.0;
        double timeStep = 1;

        // exercise
        so.applyGravity(center, gravity, timeStep);

        // verify
        assertEquals(so.velocity.dx, -563.7061507614676);
        assertEquals(so.velocity.dy, -563.7061507614676);


    }
    // teardown


    /*********************************************
    * name:    APPLY GRAVITY DIFFERENT TIMESTEP
    * input:   Center(0,0) Position(1000000,1000000)
    *          Gravity = 398600441800000.0
    *          timeStep = 0.5
    * output:  velocity(-70.46326884518345, -70.46326884518345)
    *********************************************/
    void applyGravityDifferentTimeStep()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 1000000;
        so.position.y = 1000000;
        Position center;
        center.x = 0;
        center.y = 0;
        double gravity = 398600441800000.0;
        double timeStep = 0.5;

        // exercise
        so.applyGravity(center, gravity, timeStep);

        // verify
        assertEquals(so.velocity.dx, -70.46326884518345);
        assertEquals(so.velocity.dy, -70.46326884518345);

    }
    // teardown


    /*********************************************
    * name:    UPDATE POSITION NO MOVEMENT
    * input:   position(15, 20) velocity(10, 10) timeSpent = 0
    * output:  position(15, 20) velocity(10, 10) timeSpent = 0
    *********************************************/
    void updatePositionNoMovement()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 15;
        so.position.y = 20;
        so.velocity.dx = 10;
        so.velocity.dy = 10;
        double timeSpent = 0;

        // exercise
        so.updatePosition(timeSpent);

        // verify
        assertEquals(so.position.x, 15);
        assertEquals(so.position.y, 20);
        assertEquals(so.velocity.dx, 10);
        assertEquals(so.velocity.dy, 10);
        assertEquals(timeSpent, 0);

    }
    // teardown


    /*********************************************
    * name:    UPDATE POSITION TWO AND HALF SECONDS 
    * input:   position(10, 10) velocity(10, 10) timeSpent = 0
    * output:  position(35, 35) velocity(10, 10) timeSpent = 2.5
    *********************************************/
    void updatePositionTwoAndHalfSeconds()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 10;
        so.position.y = 10;
        so.velocity.dx = 10;
        so.velocity.dy = 10;
        double timeSpent = 2.5;

        // exercise
        so.updatePosition(timeSpent);

        // verify
        assertEquals(so.position.x, 35);
        assertEquals(so.position.y, 35);
        assertEquals(so.velocity.dx, 10);
        assertEquals(so.velocity.dy, 10);
        assertEquals(timeSpent, 2.5);

    }
    // teardown


    /*********************************************
    * name:    ROTATE POSITIVE
    * input:   angle = 0, rotateAmount = 0.5
    * output:  angle = 0.5, rotateAmount = 0.5
    *********************************************/
    void rotatePositive()
    {
        // setup
        SpaceObjectDerived so;
        so.angle.radians = 0;
        double rotateAmount = 0.5;

        // exercise
        so.rotate(rotateAmount);

        // verify
        assertEquals(so.angle.radians, 0.5);
        assertEquals(rotateAmount, 0.5);

    }
    // teardown


    /*********************************************
    * name:    ROTATE NEGATIVE
    * input:   angle = 0.6, rotateAmount = -0.5
    * output:  angle = 0.1, rotateAmount = -0.5
    *********************************************/
    void rotateNegative()
    {
        // setup
        SpaceObjectDerived so;
        so.angle.radians = 0.6;
        double rotateAmount = -0.5;

        // exercise
        so.rotate(rotateAmount);

        // verify
        assertEquals(so.angle.radians, 0.1);
        assertEquals(rotateAmount, -0.5);

    }
    // teardown


    /*********************************************
    * name:    ROTATE NOTHING
    * input:   angle = 0.5, rotateAmount = 0
    * output:  angle = 0.5, rotateAmount = 0
    *********************************************/
    void rotateNothing()
    {
        // setup
        SpaceObjectDerived so;
        so.angle.radians = 0.5;
        double rotateAmount = 0;

        // exercise
        so.rotate(rotateAmount);

        // verify
        assertEquals(so.angle.radians, 0.5);
        assertEquals(rotateAmount, 0);

    }
    // teardown

    /*********************************************
    * name:    INCREMENT SECONDS ALIVE
    * input:   secondsAlive = 0, addedTime = 1
    * output:  secondsAlive = 1, addedTime = 1
    *********************************************/
    void incrementSecondsAlive()
    {
        // setup
        SpaceObjectDerived so;
        so.secondsAlive = 0;
        int addedTime = 1;

        // exercise
        so.incrementSecondsAlive(addedTime);

        // verify
        assertEquals(so.secondsAlive, 1);
        assertEquals(addedTime, 1);

    }
    // teardown


    /*********************************************
    * name:    DECREMENT SECONDS ALIVE
    * input:   secondsAlive = 1, addedTime = -1
    * output:  secondsAlive = 0, addedTime = -1
    *********************************************/
    void decrementSecondsAlive()
    {
        // setup
        SpaceObjectDerived so;
        so.secondsAlive = 1;
        int addedTime = -1;

        // exercise
        so.incrementSecondsAlive(addedTime);

        // verify
        assertEquals(so.secondsAlive, 0);
        assertEquals(addedTime, -1);

    }
    // teardown


    /*********************************************
    * name:    UPDATE OBJECT ONE SECOND
    * input:   position(1000000, 1000000) velocity (0,0)
    *          secondsAlive = 0, timeStep = 1
    * output:  position(999859.0734623096, 999859.0734623096)
    *          velocity(-140.9265376903669, -140.9265376903669)
    *          secondsAlive = 1, timeStep = 1
    *********************************************/
    void updateObjectOneSecond()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 1000000;
        so.position.y = 1000000;
        so.velocity.dx = 0;
        so.velocity.dx = 0;
        so.secondsAlive = 0;
        double timeStep = 1;

        // exercise
        so.updateObject(timeStep);

        // verify
        assertEquals(so.velocity.dy, -140.9265376903669);
        assertEquals(so.velocity.dy, -140.9265376903669);
        assertEquals(so.position.x, 999859.0734623096);
        assertEquals(so.position.y, 999859.0734623096);
        assertEquals(so.secondsAlive, 1);
        assertEquals(timeStep, 1);

    }
    // teardown


    /*********************************************
    * name:    UPDATE OBJECT ONE SECOND
    * input:   position(1000000, 1000000) velocity (0,0)
    *          secondsAlive = 0, timeStep = 0.5
    * output:  position(999929.5367311548, 999929.5367311548)
    *          velocity(-70.46326884518345, -70.46326884518345)
    *          secondsAlive = 1, timeStep = 0.5
    *********************************************/
    void updateObjectHalfSecond()
    {
        // setup
        SpaceObjectDerived so;
        so.position.x = 1000000;
        so.position.y = 1000000;
        so.velocity.dx = 0;
        so.velocity.dx = 0;
        so.secondsAlive = 0;
        double timeStep = 0.5;

        // exercise
        so.updateObject(timeStep);

        // verify
        cout << so.secondsAlive << endl;
        cout << so.position.x << endl;
        assertEquals(so.velocity.dy, -70.46326884518345);
        assertEquals(so.velocity.dy, -70.46326884518345);
        assertEquals(so.position.x, 999929.5367311548);
        assertEquals(so.position.y, 999929.5367311548);
        assertEquals(so.secondsAlive, 0.5);
        assertEquals(timeStep, 0.5);

    }
    // teardown
};