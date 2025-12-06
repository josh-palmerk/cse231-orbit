/***********************************************************************
 * Source File:
 *    TEST DRAGON
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for dragon
 ************************************************************************/

#include "testDragon.h"



 /*****************************************************************
  *****************************************************************
  * CONSTRUCTORS
  *****************************************************************
  *****************************************************************/

 /*********************************************
  * name:    DEFAULT CONSTRUCTOR
  * input:   nothing
  * output:  pos.y = 8000000.0, vel.dx = -7900.0
  *          radius = 7.0 * 128000
  *********************************************/
void TestDragon::defaultConstructor()
{
    // setup
    // exercise
    Dragon d;

    // verify
    assertEquals(d.position.x, 0.0);
    assertEquals(d.position.y, 8000000.0);
    assertEquals(d.velocity.dx, -7900.0);
    assertEquals(d.velocity.dy, 0.0);
    assertEquals(d.angle.radians, 0.0);
    assertEquals(d.radius, 7.0 * 128000);
    assertEquals(d.secondsAlive, 0);
}
// teardown


/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   pos(7.8, 2.3) velocity(4.4, 8.8)
 *          angle(-1.283) radius = 7.8
 * output:  pos(7.8, 2.3) velocity(4.4, 8.8)
 *          angle(5.0) radius = 7.8, secondsAlive = 0
 *********************************************/
void TestDragon::nonDefaultConstructor()
{
    // setup
    Position pos;
    pos.x = 7.8;
    pos.y = 2.3;
    Velocity v;
    v.dx = 4.4;
    v.dy = 8.8;
    Angle ang;
    ang.radians = atan2(-pos.y, -pos.x) + M_PI_2;
    double radius = 7.8;

    // exercise
    Dragon d(pos, v, ang, radius);

    // verify
    assertEquals(d.position.x, 7.8);
    assertEquals(d.position.y, 2.3);
    assertEquals(d.velocity.dx, 4.4);
    assertEquals(d.velocity.dy, 8.8);
    assert(fabs(d.angle.radians - 5.0) < 0.001);
    assertEquals(d.radius, 7.8);
    assertEquals(d.secondsAlive, 0);
}
// teardown