/***********************************************************************
 * Source File:
 *    TEST STARLINK
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for Starlink
 ************************************************************************/

#include "testStarlink.h"




 /*****************************************************************
 *****************************************************************
 * CONSTRUCTORS
 *****************************************************************
 *****************************************************************/

 /*********************************************
 * name:    DEFAULT CONSTRUCTOR
 * input:   nothing
 * output:  pos.y = -13020000.0, vel.dx = 5800.0
 *          radius = 6.0
 *********************************************/
void TestStarlink::defaultConstructor()
{
    // setup
    // exercise
    Starlink st;

    // verify
    assertEquals(st.position.x, 0);
    assertEquals(st.position.y, -13020000.0);
    assertEquals(st.velocity.dx, 5800.0);
    assertEquals(st.velocity.dy, 0);
    assertEquals(st.angle.radians, 0.0);
    assertEquals(st.radius, 6.0);
    assertEquals(st.secondsAlive, 0);
}
// teardown


/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   pos(150.7, 5.2) velocity(76.8, 80.2)
 *          angle(-1.536) radius = 9.8
 * output:  pos(150.7, 5.2) velocity(76.8, 80.2)
 *          angle(4.747) radius = 9.8, secondsAlive = 0
 *********************************************/
void TestStarlink::nonDefaultConstructor()
{
    // setup
    Position pos;
    pos.x = 150.7;
    pos.y = 5.2;
    Velocity v;
    v.dx = 76.8;
    v.dy = 80.2;
    Angle ang;
    ang.radians = atan2(-pos.y, -pos.x) + M_PI_2;
    double radius = 9.8;

    // exercise
    Starlink st(pos, v, ang, radius);

    // verify
    assertEquals(st.position.x, 150.7);
    assertEquals(st.position.y, 5.2);
    assertEquals(st.velocity.dx, 76.8);
    assertEquals(st.velocity.dy, 80.2);
    assert(fabs(st.angle.radians - 4.747) < 0.001);
    assertEquals(st.radius, 9.8);
    assertEquals(st.secondsAlive, 0);
}
// teardown