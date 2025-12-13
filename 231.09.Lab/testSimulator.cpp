/***********************************************************************
 * Source File:
 *    TEST SIMULATOR
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for Simulator
 ************************************************************************/

#include "testSimulator.h"
#include <vector> 
#include "simulator.h"
#include "bullet.h"


 /*****************************************************************
 *****************************************************************
 * CONSTRUCTORS
 *****************************************************************
 *****************************************************************/



 /*********************************************
  * name:    DEFAULT CONSTRUCTOR
  * input:   nothing
  * output:  spaceObjects.size = 11 stars.size = 50;
  *********************************************/
void TestSimulator::defaultConstructor()
{
    // setup
    // exercise
    Simulator sim;

    // verify
    assertEquals(static_cast<double>(sim.spaceObjects.size()), 11);
    assertEquals(static_cast<double>(sim.stars.size()), 50);
}
// teardown


 /*****************************************************************
 *****************************************************************
 * COLLISION
 *****************************************************************
 *****************************************************************/


 /*********************************************
  * name:    DRAGON COLLIDE STARLINK
  * input:   Dragon and Starlink both Pos(200, 200)
  * output:  dragon and starlink dead = true
  *********************************************/
void TestSimulator::dragonCollideStarlink()
{
    // setup
    Simulator sim;

    SpaceObject* dragon = sim.spaceObjects[9];
    SpaceObject* starlink = sim.spaceObjects[2];

    sim.spaceObjects[9]->position.x = 200; //Dragon
    sim.spaceObjects[9]->position.y = 200;

    sim.spaceObjects[2]->position.x = 200; //Starlink
    sim.spaceObjects[2]->position.y = 200;

    // exercise
    sim.objectCollisions(sim.spaceObjects);

    // verify
    assertEquals(dragon->dead, true);
    assertEquals(starlink->dead, true);
}
// teardown

/*********************************************
  * name:    HUBBLE COLLIDE EARTH
  * input:   Hubble and Earth both Pos(0, 0)
  * output:  hubble dead = true, earth dead = false
  *********************************************/
void TestSimulator::hubbleCollideEarth()
{
    // setup
    Simulator sim;
    SpaceObject* hubble = sim.spaceObjects[0];
    SpaceObject* earth = sim.spaceObjects[1];

    sim.spaceObjects[0]->position.x = 0; //Hubble
    sim.spaceObjects[0]->position.y = 0;

    sim.spaceObjects[1]->position.x = 0; //Earth
    sim.spaceObjects[1]->position.y = 0;

    // exercise
    sim.objectCollisions(sim.spaceObjects);

    // verify
    assertEquals(hubble->dead, true);
    assertEquals(earth->dead, false);
}
// teardown



/*********************************************
  * name:    DREAMCHASER COLLIDE GPS
  * input:   DreamChaser and GPS both Pos(0, 26560000.0)
  * output:  player.dead and gps dead = true
  *********************************************/
void TestSimulator::dreamChaserCollideGPS()
{
    // setup
    Simulator sim;
    SpaceObject* gps = sim.spaceObjects[3];
    sim.spaceObjects[3]->position.x = 0; //GPS
    sim.spaceObjects[3]->position.y = 26560000.0;

    sim.player.position.x = 0; //Dream Chaser
    sim.player.position.y = 26560000.0;

    // exercise
    sim.objectCollisions(sim.spaceObjects);

    // verify
    assertEquals(sim.player.dead, true);
    assertEquals(gps->dead, true);
}
// teardown
