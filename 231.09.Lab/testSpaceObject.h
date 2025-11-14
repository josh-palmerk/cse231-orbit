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

        

        //

        report("Space Object");
    }

private:

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


};