/***********************************************************************
 * Source File:
 *    TEST BULLET
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for Bullet
 ************************************************************************/

#include "testBullet.h"


 /*****************************************************************
 *****************************************************************
 * CONSTRUCTORS
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    DEFAULT CONSTRUCTOR
  * input:   nothing
  * output:  pos.x = 40000000.0, pos.y = 40000000.0,
  *          velo.dy = -2000.0, radius = 12.0
  *********************************************/
void TestBullet::defaultConstructor()
{
    // setup
    // exercise
    Bullet b;

    // verify
    assertEquals(b.position.x, 0);
    assertEquals(b.position.y, 0);
    assertEquals(b.velocity.dx, 0);
    assertEquals(b.velocity.dy, 0);
    assertEquals(b.angle.radians, 0.0);
    assertEquals(b.radius, 0.5);
    assertEquals(b.secondsAlive, 0);
}
// teardown


/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   pos(573.4, 682.9) velocity(243.1, 305.6)
 *          angle(-0.698) radius = 15.7
 * output:  pos(5.3, 4.5) velocity(7.3, 9.5)
 *          angle(5.585) radius = 15.7, secondsAlive = 0
 *********************************************/
void TestBullet::nonDefaultConstructor()
{
    // setup
    //Position pos;
    //pos.x = 573.4;
    //pos.y = 682.9;
    //Velocity v;
    //v.dx = 5723.1;
    //v.dy = 6296.6;
    //Angle ang;
    //ang.radians = atan2(-pos.y, -pos.x) + M_PI_2;
    //double radius = 15.7;

    //// exercise
    //Bullet b(pos, v, ang, radius);

    //// verify
    //assertEquals(dc.position.x, 573.4);
    //assertEquals(dc.position.y, 682.9);
    //assertEquals(dc.velocity.dx, 5723.1);
    //assertEquals(dc.velocity.dy, 6296.6);
    //assert(fabs(dc.angle.radians - 5.585) < 0.001);
    //assertEquals(dc.radius, 15.7);
    //assertEquals(dc.secondsAlive, 0);
}
// teardown