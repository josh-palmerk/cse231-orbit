/***********************************************************************
 * Source File:
 *    TEST GPS
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for GPS
 ************************************************************************/

#include "testGps.h"




 /*****************************************************************
 *****************************************************************
 * CONSTRUCTORS
 *****************************************************************
 *****************************************************************/

 /*********************************************
 * name:    DEFAULT CONSTRUCTOR
 * input:   nothing
 * output:  pos.y = -2020000000.0, radius = 12.0
 *********************************************/
void TestGPS::defaultConstructor()
{
    // setup
    // exercise
    GPS g;

    // verify
    assertEquals(g.position.x, 0);
    assertEquals(g.position.y, -2020000000.0);
    assertEquals(g.velocity.dx, 0);
    assertEquals(g.velocity.dy, 0);
    assertEquals(g.angle.radians, 0.0);
    assertEquals(g.radius, 12.0);
    assertEquals(g.secondsAlive, 0);
}
// teardown


/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   pos(1600.4, 1800.9) velocity(243.1, 305.6)
 *          angle(2.297) radius = 20.8
 * output:  pos(1600.4, 1800.9) velocity(243.1, 305.6)
 *          angle(2.297) radius = 20.8, secondsAlive = 0
 *********************************************/
void TestGPS::nonDefaultConstructor()
{
    // setup
    Position pos;
    pos.x = 1600.4;
    pos.y = 1800.9;
    Velocity v;
    v.dx = 243.1;
    v.dy = 305.6;
    Angle ang;
    ang.radians = atan2(pos.y, -pos.x);
    double radius = 20.8;

    // exercise
    GPS g(pos, v, ang, radius);

    // verify
    assertEquals(g.position.x, 1600.4);
    assertEquals(g.position.y, 1800.9);
    assertEquals(g.velocity.dx, 243.1);
    assertEquals(g.velocity.dy, 305.6);
    assert(fabs(g.angle.radians - 2.297) < 0.001);
    assertEquals(g.radius, 20.8);
    assertEquals(g.secondsAlive, 0);
}
// teardown