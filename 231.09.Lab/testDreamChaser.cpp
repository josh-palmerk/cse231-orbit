/***********************************************************************
 * Source File:
 *    TEST DREAM CHASER
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for Dream Chaser
 ************************************************************************/

#include "testDreamChaser.h"


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
void TestDreamChaser::defaultConstructor()
{
    // setup
    // exercise
    DreamChaser dc;

    // verify
    assertEquals(dc.position.x, 40000000.0);
    assertEquals(dc.position.y, 40000000.0);
    assertEquals(dc.velocity.dx, 0);
    assertEquals(dc.velocity.dy, -2000.0);
    assertEquals(dc.angle.radians, 0.0);
    assertEquals(dc.radius, 10.0);
    assertEquals(dc.secondsAlive, 0);
}
// teardown


/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   pos(573.4, 682.9) velocity(243.1, 305.6)
 *          angle(-0.698) radius = 15.7
 * output:  pos(5.3, 4.5) velocity(7.3, 9.5)
 *          angle(5.585) radius = 15.7, secondsAlive = 0
 *********************************************/
void TestDreamChaser::nonDefaultConstructor()
{
    // setup
    Position pos;
    pos.x = 573.4;
    pos.y = 682.9;
    Velocity v;
    v.dx = 5723.1;
    v.dy = 6296.6;
    Angle ang;
    ang.radians = atan2(-pos.y, -pos.x) + M_PI_2;
    double radius = 15.7;

    // exercise
    DreamChaser dc(pos, v, ang, radius);

    // verify
    assertEquals(dc.position.x, 573.4);
    assertEquals(dc.position.y, 682.9);
    assertEquals(dc.velocity.dx, 5723.1);
    assertEquals(dc.velocity.dy, 6296.6);
    assert(fabs(dc.angle.radians - 5.585) < 0.001);
    assertEquals(dc.radius, 15.7);
    assertEquals(dc.secondsAlive, 0);
}
// teardown




/*****************************************************************
*****************************************************************
* INPUT
*****************************************************************
*****************************************************************/


/*********************************************
* name:    TURN LEFT FROM ZERO
* input:   radians = 0, timeStep = 1
* output:  radians = 6.183, timeStep = 1
*********************************************/
void TestDreamChaser::turnLeftFromZero()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = 0;
    double timeStep = 1;

    Interface ui;
    Interface* pUI = &ui;
    pUI->isLeftPress = 1;

    vector<SpaceObject*> bullets;
    bullets.push_back(new DreamChaser);

    // exercise
    dc.handleInput(pUI, timeStep, bullets);

    // verify
    assert(fabs(dc.angle.radians - 6.183) < 0.001);
    assertEquals(timeStep, 1);

    // teardown
    Interface::isLeftPress = 0;
}


/*********************************************
* name:    TURN LEFT FROM POSITIVE
* input:   radians = 0.5, timeStep = 1
* output:  radians = 0.4, timeStep = 1
*********************************************/
void TestDreamChaser::turnLeftFromPositive()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = 0.5;
    double timeStep = 1;

    Interface ui;
    Interface* pUI = &ui;
    pUI->isLeftPress = 1;

    vector<SpaceObject*> bullets;
    bullets.push_back(new DreamChaser);

    // exercise
    dc.handleInput(pUI, timeStep, bullets);

    // verify
    assertEquals(dc.angle.radians, 0.4);
    assertEquals(timeStep, 1);

    // teardown
    Interface::isLeftPress = 0;
}


/*********************************************
* name:    TURN LEFT FROM NEGATIVE
* input:   radians = -0.5, timeStep = 1
* output:  radians = 5.6832, timeStep = 1
*********************************************/
void TestDreamChaser::turnLeftFromNegative()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = -0.5;
    double timeStep = 1;

    Interface ui;
    Interface* pUI = &ui;
    pUI->isLeftPress = 1;

    vector<SpaceObject*> bullets;
    bullets.push_back(new DreamChaser);

    // exercise
    dc.handleInput(pUI, timeStep, bullets);

    // verify
    assert(fabs(dc.angle.radians - 5.6832) < 0.001);
    assertEquals(timeStep, 1);

    // teardown
    Interface::isLeftPress = 0;
}



/*********************************************
* name:    TURN RIGHT FROM ZERO
* input:   radians = 0, timeStep = 1
* output:  radians = 0.1, timeStep = 1
*********************************************/
void TestDreamChaser::turnRightFromZero()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = 0;
    double timeStep = 1;

    Interface ui;
    Interface* pUI = &ui;
    pUI->isRightPress = 1;

    vector<SpaceObject*> bullets;
    bullets.push_back(new DreamChaser);

    // exercise
    dc.handleInput(pUI, timeStep, bullets);

    // verify
    assert(dc.angle.radians, 0.1);
    assertEquals(timeStep, 1);

    // teardown
    Interface::isRightPress = 0;

}


/*********************************************
* name:    TURN RIGHT FROM POSITIVE
* input:   radians = 0.5, timeStep = 1
* output:  radians = 0.6, timeStep = 1
*********************************************/
void TestDreamChaser::turnRightFromPositive()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = 0.5;
    double timeStep = 1;

    Interface ui;
    Interface* pUI = &ui;
    pUI->isRightPress = 1;

    vector<SpaceObject*> bullets;
    bullets.push_back(new DreamChaser);

    // exercise
    dc.handleInput(pUI, timeStep, bullets);

    // verify
    assertEquals(dc.angle.radians, 0.6);
    assertEquals(timeStep, 1);

    // teardown
    Interface::isRightPress = 0;
}


/*********************************************
* name:    TURN RIGHT FROM NEGATIVE
* input:   radians = -0.5, timeStep = 1
* output:  radians = 5.8832, timeStep = 1
*********************************************/
void TestDreamChaser::turnRightFromNegative()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = -0.5;
    double timeStep = 1;

    Interface ui;
    Interface* pUI = &ui;
    pUI->isRightPress = 1;

    vector<SpaceObject*> bullets;
    bullets.push_back(new DreamChaser);

    // exercise
    dc.handleInput(pUI, timeStep, bullets);

    // verify
    assert(fabs(dc.angle.radians - 5.8832) < 0.001);
    assertEquals(timeStep, 1);

    // teardown
    Interface::isRightPress = 0;
}


/*********************************************
* name:    THRUSTER TURNS ON
* input:    velocity (0, 0), timeStep = 1
* output:   velocity (0, 2), timeStep = 1
*********************************************/
void TestDreamChaser::thrusterTurnsOn()
{
    // setup
    DreamChaser dc;
    dc.velocity.dx = 0;
    dc.velocity.dy = 0;
    double timeStep = 1;

    Interface ui;
    Interface* pUI = &ui;
    pUI->isDownPress = 1;

    vector<SpaceObject*> bullets;
    bullets.push_back(new DreamChaser);

    // exercise
    dc.handleInput(pUI, timeStep, bullets);

    // verify
    assertEquals(dc.velocity.dx, 0);
    assertEquals(dc.velocity.dy, 2.0);
    assertEquals(timeStep, 1.0);

    // teardown
    Interface::isDownPress = 0;
}

/*********************************************
* name:    ADD THRUST POSITIVE ANGLE
* input:    radians = 0.5 velocity (0, 0), timeStep = 1
* output:   velocity (0.9588, 1.7552), timeStep = 1
*********************************************/
void TestDreamChaser::addThrustPositiveAngle()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = 0.5;
    dc.velocity.dx = 0;
    dc.velocity.dy = 0;
    double timeStep = 1;

    // exercise
    dc.addThrust(timeStep);

    // verify
    assertEquals(dc.velocity.dx, 0.9588);
    assertEquals(dc.velocity.dy, 1.7552);
    assertEquals(dc.angle.radians, 0.5);
    assertEquals(timeStep, 1.0);

    // teardown
}


/*********************************************
* name:    ADD THRUST NEGATIVE ANGLE
* input:    radians = 0.5 velocity (0, 0), timeStep = 1
* output:   velocity (-0.9588, 1.7552), timeStep = 1
*********************************************/
void TestDreamChaser::addThrustNegativeAngle()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = -0.5;
    dc.velocity.dx = 0;
    dc.velocity.dy = 0;
    double timeStep = 1;

    // exercise
    dc.addThrust(timeStep);

    // verify
    assertEquals(dc.velocity.dx, -0.9588);
    assertEquals(dc.velocity.dy, 1.7552);
    assertEquals(dc.angle.radians, -0.5);
    assertEquals(timeStep, 1.0);

    // teardown
}


/*********************************************
* name:    ADD THRUST DIFFERENT TIMESTEP
* input:    velocity (0, 0), timeStep = 2
* output:   velocity (0, 4), timeStep = 2
*********************************************/
void TestDreamChaser::addThrustDifferentTimeStep()
{
    // setup
    DreamChaser dc;
    dc.velocity.dx = 0;
    dc.velocity.dy = 0;
    double timeStep = 2;

    // exercise
    dc.addThrust(timeStep);

    // verify
    assertEquals(dc.velocity.dx, 0);
    assertEquals(dc.velocity.dy, 4);
    assertEquals(timeStep, 2.0);

    // teardown
}


/*********************************************
* name:    ADD THRUST TO EXISTING VELOCITY
* input:    radians = 0.5 velocity (7.5, 8.8), timeStep = 1
* output:   velocity (8.4588, 10.5552), timeStep = 1
*********************************************/
void TestDreamChaser::addThrustToExistingVelocity()
{
    // setup
    DreamChaser dc;
    dc.angle.radians = 0.5;
    dc.velocity.dx = 7.5;
    dc.velocity.dy = 8.8;
    double timeStep = 1;

    // exercise
    dc.addThrust(timeStep);

    // verify
    assertEquals(dc.velocity.dx, 8.4588);
    assertEquals(dc.velocity.dy, 10.5552);
    assertEquals(dc.angle.radians, 0.5);
    assertEquals(timeStep, 1.0);

    // teardown
}