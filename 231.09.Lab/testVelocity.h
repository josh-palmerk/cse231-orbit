/***********************************************************************
 * Header File:
 *    TEST VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Unit tests for the Velocity class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "velocity.h"
#include "angle.h"
#include "acceleration.h"

/*********************************************
 * TEST VELOCITY
 * Unit tests for Velocity
 *********************************************/
class TestVelocity : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: Without Add
      constructor_default();
      constructor_nonDefault();
      getDX();
      getDY();
      getSpeed_up();
      getSpeed_down();
      getSpeed_left();
      getSpeed_right();
      getSpeed_diagonal();
      getSpeed_zero();
      setDX();
      setDY();
      set_up();
      set_down();
      set_left();
      set_right();
      set_diagonal();
      
      // Ticket 2: Add
      addDX_zero();
      addDX_value();
      addDY_zero();
      addDY_value();
      add_stationary();
      add_noTime();
      add_moving4Seconds();
      add_moving1Second();

      report("Velocity");
   }

private:

    void constructor_default();
    void constructor_nonDefault();
    void getDX();
    void getDY();
    void getSpeed_zero();
    void getSpeed_up();
    void getSpeed_down();
    void getSpeed_left();
    void getSpeed_right();
    void getSpeed_diagonal();
    void setDX();
    void setDY();
    void set_up();
    void set_down();
    void set_left();
    void set_right();
    void set_diagonal();
    void addDX_zero();
    void addDX_value();
    void addDY_zero();
    void addDY_value();
    void add_stationary();
    void add_noTime();
    void add_moving4Seconds();
    void add_moving1Second();

};
