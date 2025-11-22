/***********************************************************************
 * Header File:
 *    TEST GPS
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for GPS
 ************************************************************************/

#pragma once


#include "gps.h"
#include "unitTest.h"

 /*******************************
  * TEST GPS
  * A friend class for GPS which contains the GPS unit tests
  ********************************/
class TestGPS : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();


        report("GPS");
    }



private:

    void defaultConstructor();
    void nonDefaultConstructor();

};
