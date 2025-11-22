/***********************************************************************
 * Header File:
 *    TEST ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for ANGLE
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "angle.h"

/*******************************
 * TEST ANGLE
 * A friend class for Angle which contains the Angle unit tests
 ********************************/
class TestAngle : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: Angle Without Normalize
      defaultConstructor();
      setUp();
      setDown();
      setRight();
      setLeft();
      reverse();
      setRadians_noNormalize();
      setDegrees_noNormalize();
      getDegrees_0();
      getDegrees_270();
      getRadians_0();
      getRadians_270();
      add_0();
      add_value();

      // Ticket 2: Angle Normalize
      setRadians_negative();
      setRadians_oneLap();
      setRadians_sixLaps();
      setRadians_negativeThreeQuarters();
      setRadians_negativeOneLap();
      setRadians_negativeSixLaps();
      setDegrees_negative();
      setDegrees_oneLap();
      setDegrees_sixLaps();
      setDegrees_negativeThreeQuarters();
      setDegrees_negativeOneLap();
      setDegrees_negativeSixLaps();
      add_positiveLap();
      add_negativeLap();

      report("Angle");
   }

private:

    void defaultConstructor();
    void setUp();
    void setDown();
    void setRight();
    void setLeft();
    void reverse();
    void setRadians_noNormalize();
    void setDegrees_noNormalize();
    void getDegrees_0();
    void getDegrees_270();
    void getRadians_0();
    void getRadians_270();
    void add_0();
    void add_value();
    void setRadians_negative();
    void setRadians_oneLap();
    void setRadians_sixLaps();
    void setRadians_negativeThreeQuarters();
    void setRadians_negativeOneLap();
    void setRadians_negativeSixLaps();
    void setDegrees_negative();
    void setDegrees_oneLap();
    void setDegrees_sixLaps();
    void setDegrees_negativeThreeQuarters();
    void setDegrees_negativeOneLap();
    void setDegrees_negativeSixLaps();
    void add_positiveLap();
    void add_negativeLap();
   
   
};
