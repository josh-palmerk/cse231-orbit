/***********************************************************************
 * Header File:
 *    TEST STAR
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for Star
 ************************************************************************/
#pragma once

#include "star.h"
#include "unitTest.h"


/*******************************
 * TEST Sputnik
 * A friend class for Sputnik which contains the Sputnik unit tests
 ********************************/
class TestStar : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();

        incrementPhase();
        incrementPhaseLoop();


        report("Star");
    }



private:
   void defaultConstructor();
   void incrementPhase();
   void incrementPhaseLoop();
    

};
