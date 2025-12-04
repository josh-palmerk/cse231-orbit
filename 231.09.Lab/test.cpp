/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testAngle.h"
#include "testVelocity.h"
#include "testAcceleration.h"
#include "testSpaceObject.h"
#include "testHubble.h"
#include "testEarth.h"
#include "testDragon.h"
#include "testSputnik.h"
#include "testStarlink.h"
#include "testGPS.h"
#include "testDreamChaser.h"
#include "testStar.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   TestPosition().run();
   TestAngle().run();
   TestVelocity().run();
   TestAcceleration().run();
   TestSpaceObject().run();
   TestHubble().run();
   TestEarth().run();
   TestDragon().run();
   TestSputnik().run();
   TestStarlink().run();
   TestGPS().run();
   TestDreamChaser().run();
   TestStar().run();
}
