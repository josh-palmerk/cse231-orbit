/***********************************************************************
 * Header File:
 *    TEST SPUTNIK
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for SPUTNIK
 ************************************************************************/

#pragma once


#include "sputnik.h"
#include "unitTest.h"


 /*******************************
  * TEST Sputnik
  * A friend class for Sputnik which contains the Sputnik unit tests
  ********************************/
class TestSputnik : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();


        report("Sputnik");
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
    * output:  pos.x = -36515095.13, pos.y = 21082000.0
    *          vel.dx = 2050.0, vel.dy = 2684.68
    *          radius = 4.0
    *********************************************/
    void defaultConstructor()
    {
        // setup
        // exercise
        Sputnik s;

        // verify
        assertEquals(s.position.x, -36515095.13);
        assertEquals(s.position.y, 21082000.0);
        assertEquals(s.velocity.dx, 2050.0);
        assertEquals(s.velocity.dy, 2684.68);
        assertEquals(s.angle.radians, 0.0);
        assertEquals(s.radius, 4.0);
        assertEquals(s.secondsAlive, 0);
    }
    // teardown


    /*********************************************
     * name:    NON DEFAULT CONSTRUCTOR
     * input:   pos(20.3, 18.3) velocity(26.2, 23.1)
     *          angle(-0.837) radius = 2.8
     * output:  pos(20.3, 18.3) velocity(26.2, 23.1)
     *          angle(5.446) radius = 2.8, secondsAlive = 0
     *********************************************/
    void nonDefaultConstructor()
    {
        // setup
        Position pos;
        pos.x = 20.3;
        pos.y = 18.3;
        Velocity v;
        v.dx = 26.2;
        v.dy = 23.1;
        Angle ang;
        ang.radians = atan2(-pos.y, -pos.x) + M_PI_2;
        double radius = 2.8;

        // exercise
        Sputnik s(pos, v, ang, radius);

        // verify 
        assertEquals(s.position.x, 20.3);
        assertEquals(s.position.y, 18.3);
        assertEquals(s.velocity.dx, 26.2);
        assertEquals(s.velocity.dy, 23.1);
        assert(fabs(s.angle.radians - 5.446) < 0.001);
        assertEquals(s.radius, 2.8);
        assertEquals(s.secondsAlive, 0);
    }
    // teardown

};
