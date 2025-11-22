/***********************************************************************
 * Source File:
 *    TEST ANGLE
 * Author:
 *    Garrin and Josh
 * Summary:
 *    The unit tests for angle
 ************************************************************************/

#include "testAngle.h"



 /*****************************************************************
  *****************************************************************
  * CONSTRUCTOR
  *****************************************************************
  *****************************************************************/


 /*********************************************
  * name:    DEFAULT CONSTRUCTOR
  * input:   nothing
  * output:  zero
  *********************************************/
void TestAngle::defaultConstructor()
{  // setup
   // exercise
    Angle a;
    // verify
    assertUnit(a.radians == 0.0);
}  // teardown

/*****************************************************************
 *****************************************************************
 * SETTERS
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    SET UP
  * input:   nothing
  * output:  0 degrees
  *********************************************/
void TestAngle::setUp()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setUp();
    // verify
    assertEquals(a.radians, 0.0);
}  // teardown

/*********************************************
 * name:    SET DOWN
 * input:   nothing
 * output:  180 degrees
 *********************************************/
void TestAngle::setDown()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setDown();
    // verify
    assertEquals(a.radians, M_PI);
}  // teardown

/*********************************************
 * name:    SET RIGHT
 * input:   nothing
 * output:  90 degrees
 *********************************************/
void TestAngle::setRight()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setRight();
    // verify
    assertEquals(a.radians, M_PI_2);
}  // teardown

/*********************************************
 * name:    SET LEFT
 * input:   nothing
 * output:  270 degrees
 *********************************************/
void TestAngle::setLeft()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setLeft();
    // verify
    assertEquals(a.radians, M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    REVERSE
 * input:   90
 * output:  270 degrees
 *********************************************/
void TestAngle::reverse()
{  // setup
    Angle a;
    a.radians = M_PI_2; // 90 degrees
    // exercise
    a.reverse();
    // verify
    assertEquals(a.radians, M_PI_2 + M_PI);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NO NORMALIZATION
 * input:   45 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_noNormalize()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setRadians(0.785398);
    // verify
    assertEquals(a.radians, 0.785398);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NEGATIVE
 * input:   -90
 * output:  270 degrees
 *********************************************/
void TestAngle::setRadians_negative()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setRadians(-M_PI_2);
    // verify
    assertEquals(a.radians, M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    SET RADIANS - ONE LAP
 * input:   45 + 360 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_oneLap()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setRadians(0.785398 + (M_PI * 2.0));
    // verify
    assertEquals(a.radians, 0.785398);
}  // teardown

/*********************************************
 * name:    SET RADIANS - SIX LAP
 * input:   45 + (6 x 360) degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_sixLaps()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setRadians(0.785398 + (M_PI * 2.0) * 6.0);
    // verify
    assertEquals(a.radians, 0.785398);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NEGATIVE 3/4
 * input:   -270 degrees
 * output:  90 degrees
 *********************************************/
void TestAngle::setRadians_negativeThreeQuarters()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setRadians(-M_PI - M_PI_2);
    // verify
    assertEquals(a.radians, M_PI_2);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NEGATIVE ONE LAP
 * input:   -45 - 360 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setRadians_negativeOneLap()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setRadians(-0.785398 - (M_PI * 2.0));
    // verify
    assertEquals(a.radians, 5.49779);
}  // teardown

/*********************************************
 * name:    SET RADIANS - NEGATIVE SIX LAP
 * input:   -45 - 360*6 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setRadians_negativeSixLaps()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setRadians(-0.785398 - (M_PI * 2.0) * 6.0);
    // verify
    assertEquals(a.radians, 5.49779);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NO NORMALIZATION
 * input:   45 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setDegrees_noNormalize()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setDegrees(45.0);
    // verify
    assertEquals(a.radians, 0.785398);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NEGATIVE
 * input:   -90
 * output:  270 degrees
 *********************************************/
void TestAngle::setDegrees_negative()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setDegrees(-90.0);
    // verify
    assertEquals(a.radians, M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    SET DEGREES - ONE LAP
 * input:   45 + 360 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setDegrees_oneLap()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setDegrees(45.0 + 360.0);
    // verify
    assertEquals(a.radians, 0.785398);
}  // teardown

/*********************************************
 * name:    SET DEGREES - SIX LAP
 * input:   45 + (6 x 360) degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setDegrees_sixLaps()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setDegrees(45.0 + 360.0 * 6.0);
    // verify
    assertEquals(a.radians, 0.785398);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NEGATIVE 3/4
 * input:   -270 degrees
 * output:  90 degrees
 *********************************************/
void TestAngle::setDegrees_negativeThreeQuarters()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setDegrees(-270.0);
    // verify
    assertEquals(a.radians, M_PI_2);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NEGATIVE ONE LAP
 * input:   -45 - 360 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setDegrees_negativeOneLap()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setDegrees(-45.0 - 360.0);
    // verify
    assertEquals(a.radians, 5.49779);
}  // teardown

/*********************************************
 * name:    SET DEGREES - NEGATIVE SIX LAP
 * input:   -45 - 360*6 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setDegrees_negativeSixLaps()
{  // setup
    Angle a;
    a.radians = -99.9;
    // exercise
    a.setDegrees(-45.0 - 360.0 * 6.0);
    // verify
    assertEquals(a.radians, 5.49779);
}  // teardown

/*****************************************************************
 *****************************************************************
 * ADD
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    ADD ZERO
  * input:   (45 degrees) 0
  * output:  45 degrees
  *********************************************/
void TestAngle::add_0()
{  // setup
    Angle a;
    a.radians = 0.785398;
    double r = 0.0;

    // exercise
    a.add(r);

    // verify
    assertEquals(a.radians, 0.785398);
    assertEquals(r, 0.0);
}  // teardown

/*********************************************
 * name:    ADD VALUE
 * input:   (45 degrees) 180 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::add_value()
{  // setup
    Angle a;
    a.radians = 0.785398;
    double r = M_PI;

    // exercise
    a.add(r);

    // verify
    assertEquals(a.radians, 0.785398 + M_PI);
    assertEquals(r, M_PI);
}  // teardown

/*********************************************
 * name:    ADD POSITIVE ONE LAP
 * input:   (45 degrees) 180 + 360 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::add_positiveLap()
{  // setup
    Angle a;
    a.radians = 0.785398;
    double r = M_PI + M_PI * 2.0;

    // exercise
    a.add(r);

    // verify
    assertEquals(a.radians, 0.785398 + M_PI);
    assertEquals(r, M_PI + M_PI * 2.0);
}  // teardown

/*********************************************
 * name:    ADD NEGATIVE ONE LAP
 * input:   (45 degrees) -90 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::add_negativeLap()
{  // setup
    Angle a;
    a.radians = 0.785398;
    double r = -M_PI_2;

    // exercise
    a.add(r);

    // verify
    assertEquals(a.radians, 5.49779);
    assertEquals(r, -M_PI_2);
}  // teardown

/*****************************************************************
 *****************************************************************
 * GETTERS
 *****************************************************************
 *****************************************************************/

 /*********************************************
  * name:    GET DEGREES - 0
  * input:   0 degrees
  * output:  0 degrees
  *********************************************/
void TestAngle::getDegrees_0()
{  // setup
    Angle a;
    a.radians = 0.0;
    double d = -99.9;
    // exercise
    d = a.getDegrees();
    // verify
    assertEquals(d, 0.0);
    assertEquals(a.radians, 0.0);
}  // teardown

/*********************************************
 * name:    GET DEGREES - 270
 * input:   270 degrees
 * output:  270 degrees
 *********************************************/
void TestAngle::getDegrees_270()
{  // setup
    Angle a;
    a.radians = M_PI + M_PI_2;
    double d = -99.9;
    // exercise
    d = a.getDegrees();
    // verify
    assertEquals(d, 270.0);
    assertEquals(a.radians, M_PI + M_PI_2);
}  // teardown

/*********************************************
 * name:    GET RADIANS - 0
 * input:   0 degrees
 * output:  0 degrees
 *********************************************/
void TestAngle::getRadians_0()
{  // setup
    Angle a;
    a.radians = 0.0;
    double r = -99.9;
    // exercise
    r = a.getRadians();
    // verify
    assertEquals(r, 0.0);
    assertEquals(a.radians, 0.0);
}  // teardown

/*********************************************
 * name:    GET RADIANS - 270
 * input:   270 degrees
 * output:  270 degrees
 *********************************************/
void TestAngle::getRadians_270()
{  // setup
    Angle a;
    a.radians = M_PI + M_PI_2;
    double r = -99.9;
    // exercise
    r = a.getRadians();
    // verify
    assertEquals(r, M_PI + M_PI_2);
    assertEquals(a.radians, M_PI + M_PI_2);
}  // teardown