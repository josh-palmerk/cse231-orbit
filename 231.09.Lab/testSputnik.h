/***********************************************************************
 * Header File:
 *    TEST SPUTNIK
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for SPUTNIK
 ************************************************************************/

#pragma once


#include "sputnik.h"
#include "unitTest.h"


 /*******************************
  * TEST Sputnik
  * A friend class for Sputnik which contains the Sputnik unit tests
  ********************************/
class TestSputnik : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();


        report("Sputnik");
    }



private:

    void defaultConstructor();
    void nonDefaultConstructor();

};
