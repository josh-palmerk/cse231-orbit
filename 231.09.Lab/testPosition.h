/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include "position.h"
#include "unitTest.h"

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition : public UnitTest
{
public:
   void run()
   {
      // Constructors
      construct_default();
      construct_nonDefault();
      construct_copy();
      assign();
 
      // Setters
      setMetersX();
      setMetersY();
      
      // Getters
      getMetersX();
      getMetersY();

      report("Position");
   }
   
private:

    void construct_default();
    void construct_nonDefault();
    void construct_copy();
    void assign();
    void setMetersX();
    void setMetersY();
    void getMetersX();
    void getMetersY();

};
