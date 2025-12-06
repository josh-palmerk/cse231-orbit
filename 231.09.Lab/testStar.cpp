/***********************************************************************
 * Source File:
 *    TEST STAR
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for Star
 ************************************************************************/

#include "testStar.h"



 /*****************************************************************
 *****************************************************************
 * CONSTRUCTORS
 *****************************************************************
 *****************************************************************/

 /*********************************************
 * name:    DEFAULT CONSTRUCTOR
 * input:   nothing
 * output:  
 *********************************************/
void TestStar::defaultConstructor()
{
    // setup
    // exercise
    Star s;

    // verify
    assertEquals(s.position.x, 0.0);
    assertEquals(s.position.y, 0.0);
    assertEquals(s.phase, 0.0);
    
}
// teardown


 /*********************************************
 * name:    INCREMENT PHASE
 * input:   phase = 5
 * output:  phase = 6
 *********************************************/
void TestStar::incrementPhase()
{
    // setup
    Star s;
    s.phase = 5;

    // exercise
    s.incrementPhase();

    // verify
    assertEquals(s.phase, 6);

}
// teardown

 /*********************************************
 * name:    INCREMENT PHASE
 * input:   phase = 255
 * output:  phase = 0
 *********************************************/
void TestStar::incrementPhaseLoop()
{
    // setup
    Star s;
    s.phase = 255;

    // exercise
    s.incrementPhase();

    // verify
    assertEquals(s.phase, 0);

}
// teardown