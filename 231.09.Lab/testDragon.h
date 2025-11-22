/***********************************************************************
 * Header File:
 *    TEST DRAGON
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for DRAGON
 ************************************************************************/

#pragma once


#include "hubble.h"
#include "unitTest.h"


 /*******************************
  * TEST Dragon
  * A friend class for Dragon which contains the Dragon unit tests
  ********************************/
class TestDragon : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();


        report("Dragon");
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
        Hubble h;

        // verify
        assertEquals(h.position.x, 0.0);
        assertEquals(h.position.y, -42164000.0);
        assertEquals(h.velocity.dx, 3100.0);
        assertEquals(h.velocity.dy, 0.0);
        assertEquals(h.angle.radians, 0.0);
        assertEquals(h.radius, 0.0);
        assertEquals(h.secondsAlive, 0);
    }
    // teardown


    /*********************************************
     * name:    NON DEFAULT CONSTRUCTOR
     * input:   pos(5.3, 4.5) velocity(7.3, 9.5)
     *          angle(0.3) radius = 3.8
     * output:  pos(5.3, 4.5) velocity(7.3, 9.5)
     *          angle(0.3) radius = 3.8, secondsAlive = 0
     *********************************************/
    void nonDefaultConstructor()
    {
        // setup
        Position pos;
        pos.x = 5.3;
        pos.y = 4.5;
        Velocity v;
        v.dx = 7.3;
        v.dy = 9.5;
        Angle ang;
        ang.radians = 0.3;
        double radius = 3.8;

        // exercise
        Hubble h(pos, v, ang, radius);

        // verify
        assertEquals(h.position.x, 5.3);
        assertEquals(h.position.y, 4.5);
        assertEquals(h.velocity.dx, 7.3);
        assertEquals(h.velocity.dy, 9.5);
        assertEquals(h.angle.radians, 0.3);
        assertEquals(h.radius, 3.8);
        assertEquals(h.secondsAlive, 0);
    }
    // teardown

};
