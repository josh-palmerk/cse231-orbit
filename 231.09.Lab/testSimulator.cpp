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
    assertEquals(sim.spaceObjects.size(), 11);
    assertEquals(sim.stars.size(), 50);
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
  * output:  spaceObjects.size = 9
  *********************************************/
void TestSimulator::dragonCollideStarlink()
{
    // setup
    Simulator sim;
    sim.spaceObjects[9]->position.x = 200; //Dragon
    sim.spaceObjects[9]->position.y = 200;

    sim.spaceObjects[2]->position.x = 200; //Starlink
    sim.spaceObjects[2]->position.y = 200;

    // exercise
    sim.objectCollisions(sim.spaceObjects);
    cout << sim.spaceObjects.size() << endl;
    cout << sim.spaceObjects[9]->dead << endl;

    // verify
    assertEquals(sim.spaceObjects.size(), 9);
    assertEquals(sim.spaceObjects[9]->dead, true);
}
// teardown

/*********************************************
  * name:    HUBBLE COLLIDE EARTH
  * input:   Hubble and Earth both Pos(0, 0)
  * output:  spaceObjects.size = 11
  *********************************************/
void TestSimulator::hubbleCollideEarth()
{
    // setup
    Simulator sim;
    sim.spaceObjects[0]->position.x = 0; //Hubble
    sim.spaceObjects[0]->position.y = 0;

    sim.spaceObjects[1]->position.x = 0; //Earth
    sim.spaceObjects[1]->position.y = 0;

    // exercise
    sim.objectCollisions(sim.spaceObjects);

    // verify
    assertEquals(sim.spaceObjects.size(), 10);
}
// teardown



/*********************************************
  * name:    DREAMCHASER COLLIDE GPS
  * input:   DreamChaser and GPS both Pos(0, 26560000.0)
  * output:  player.dead = true
  *********************************************/
void TestSimulator::dreamChaserCollideGPS()
{
    // setup
    Simulator sim;
    sim.spaceObjects[3]->position.x = 0; //GPS
    sim.spaceObjects[3]->position.y = 26560000.0;

    sim.player.position.x = 0; //Dream Chaser
    sim.player.position.y = 26560000.0;

    // exercise
    sim.objectCollisions(sim.spaceObjects);

    // verify
    assertEquals(sim.player.dead, true);
}
// teardown
