/***********************************************************************
 * Header File:
 *    Test Hubble : Test the Hubble class
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for Hubble
 ************************************************************************/

#pragma once

#include "hubble.h"
#include "unitTest.h"
#include <iomanip>


/*******************************
 * TEST Hubble
 * A friend class for Hubble which contains the Hubble unit tests
 ********************************/
class TestHubble : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();
        

        report("Hubble");
    }



private:

    void defaultConstructor();
    void nonDefaultConstructor();

};



