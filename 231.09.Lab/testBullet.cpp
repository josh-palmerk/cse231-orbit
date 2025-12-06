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
  * output:  pos.x = 0, pos.y = 0, velo.dx = 0,
  *          velo.dy = 0, radians = 0,
  *          radius = 0.5 * 128000, secondsAlive = 0
  *          dead = false
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
    assertEquals(b.radius, 0.5 * 128000);
    assertEquals(b.secondsAlive, 0);
    assertEquals(b.dead, false);
}
// teardown


/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   pos(543.5, 622.9) velocity(5723.1, 6296.6)
 * output:  pos(543.5, 622.9) velocity(5723.1, 6296.6)
 *********************************************/
void TestBullet::nonDefaultConstructor()
{
    // setup
    Position pos;
    pos.x = 543.5;
    pos.y = 622.9;
    Velocity v;
    v.dx = 5723.1;
    v.dy = 6296.6;

    // exercise
    Bullet b(pos, v);

    // verify
    assertEquals(b.position.x, 543.5);
    assertEquals(b.position.y, 622.9);
    assertEquals(b.velocity.dx, 5723.1);
    assertEquals(b.velocity.dy, 6296.6);
  
}
// teardown

/*********************************************
 * name:    DIE
 * input:   dead = false
 * output:  dead = true
 *********************************************/
void TestBullet::die()
{
    // setup
    Bullet b;
    b.dead = false;

    // exercise
    b.die();

    // verify
    assertEquals(b.dead, true);
}
// teardown


/*********************************************
 * name:    UPDATE OBJECT DEAD AFTER TIME PASSES
 * input:   dead = false, timestep = 48, secondsAlive = 4000
 * output:  dead = true, timestep = 48, secondsAlive = 4048 
 *********************************************/
void TestBullet::updateObjectDeadAfterTimePasses()
{
    // setup
    Bullet b;
    b.dead = false;
    b.secondsAlive = 4000;
    double timestep = 48;
    vector<SpaceObject*> spaceObjects;

    // exercise
    b.updateObject(timestep, spaceObjects);

    // verify
    assertEquals(b.dead, true);
    assertEquals(b.secondsAlive, 4048);
    assertEquals(timestep, 48);
}

/*********************************************
 * name:    UPDATE OBJECT DIES AFTER TIME PASSES
 * input:   dead = false, timestep = 50, secondsAlive = 3350
 * output:  dead = true, timestep = 50, secondsAlive = 3400
 *********************************************/
void TestBullet::updateObjectDiesAfterTimePasses()
{
    // setup
    Bullet b;
    b.dead = false;
    b.secondsAlive = 3350;
    double timestep = 50;
    vector<SpaceObject*> spaceObjects;

    // exercise
    b.updateObject(timestep, spaceObjects);

    // verify
    assertEquals(b.dead, true);
    assertEquals(b.secondsAlive, 3400);
    assertEquals(timestep, 50);
}

/*********************************************
 * name:    UPDATE OBJECT ALIVE AFTER TIME PASSES
 * input:   dead = false, timestep = 50, secondsAlive = 3300
 * output:  dead = false, timestep = 50, secondsAlive = 3350
 *********************************************/
void TestBullet::updateObjectAliveAfterTimePasses()
{
    // setup
    Bullet b;
    b.dead = false;
    b.secondsAlive = 3300;
    double timestep = 50;
    vector<SpaceObject*> spaceObjects;

    // exercise
    b.updateObject(timestep, spaceObjects);

    // verify
    assertEquals(b.dead, false);
    assertEquals(b.secondsAlive, 3350);
    assertEquals(timestep, 50);
}