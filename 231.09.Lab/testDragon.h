/***********************************************************************
 * Header File:
 *    TEST DRAGON
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for DRAGON
 ************************************************************************/

#pragma once


#include "dragon.h"
#include "unitTest.h"


 /*******************************
  * TEST Dragon
  * A friend class for Dragon which contains the Dragon unit tests
  ********************************/
class TestDragon : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();


        report("Dragon");
    }



private:

    void defaultConstructor();
    void nonDefaultConstructor();

    

};
