/***********************************************************************
 * Source File:
 *    TEST HUBBLE
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for Hubble
 ************************************************************************/


#include "testHubble.h"


 /*****************************************************************
 *****************************************************************
 * CONSTRUCTORS
 *****************************************************************
 *****************************************************************/

 /*********************************************
 * name:    DEFAULT CONSTRUCTOR
 * input:   nothing
 * output:  pos.y = -42164000.0, vel.dx = 3100.0
 *          radius = 10.0
 *********************************************/
void TestHubble::defaultConstructor()
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
    assertEquals(h.radius, 10.0);
    assertEquals(h.secondsAlive, 0);
}
// teardown


/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   pos(5.3, 4.5) velocity(7.3, 9.5)
 *          angle(-0.86545) radius = 3.8
 * output:  pos(5.3, 4.5) velocity(7.3, 9.5)
 *          angle(5.4) radius = 3.8, secondsAlive = 0
 *********************************************/
void TestHubble::nonDefaultConstructor()
{
    // setup
    Position pos;
    pos.x = 5.3;
    pos.y = 4.5;
    Velocity v;
    v.dx = 7.3;
    v.dy = 9.5;
    Angle ang;
    ang.radians = atan2(-pos.y, -pos.x) + M_PI_2;
    double radius = 3.8;

    // exercise
    Hubble h(pos, v, ang, radius);

    // verify
    assertEquals(h.position.x, 5.3);
    assertEquals(h.position.y, 4.5);
    assertEquals(h.velocity.dx, 7.3);
    assertEquals(h.velocity.dy, 9.5);
    assert(fabs(h.angle.radians - 5.4177) < 0.005);
    assertEquals(h.radius, 3.8);
    assertEquals(h.secondsAlive, 0);
}
// teardown