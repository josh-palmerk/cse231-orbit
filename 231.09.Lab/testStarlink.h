/***********************************************************************
 * Header File:
 *    TEST STARLINK
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for STARLINK
 ************************************************************************/

#pragma once


#include "starlink.h"
#include "unitTest.h"


 /*******************************
  * TEST Starlink
  * A friend class for Starlink which contains the Starlink unit tests
  ********************************/
class TestStarlink : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();


        report("Starlink");
    }



private:

    void defaultConstructor();
    void nonDefaultConstructor();

};
