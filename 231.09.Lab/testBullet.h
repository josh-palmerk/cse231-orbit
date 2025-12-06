/***********************************************************************
 * Header File:
 *    TEST BULLET
 * Author:
 *    Josh and Garrin
 * Summary:
 *    All the unit tests for Bullet
 ************************************************************************/

#pragma once


#include "bullet.h"
#include "unitTest.h"


 /*******************************
  * TEST Bullet
  * A friend class for Bullet which contains the Bullet unit tests
  ********************************/
class TestBullet : public UnitTest
{
public:

    void run()
    {
        // Constructors
        defaultConstructor();
        nonDefaultConstructor();

        //Interactions
        die();
        updateObjectDeadAfterTimePasses();
        updateObjectDiesAfterTimePasses();
        updateObjectAliveAfterTimePasses();
        report("Bullet");
    }



private:
    void defaultConstructor();
    void nonDefaultConstructor();
    void die();
    void updateObjectDeadAfterTimePasses();
    void updateObjectDiesAfterTimePasses();
    void updateObjectAliveAfterTimePasses();
    



};
