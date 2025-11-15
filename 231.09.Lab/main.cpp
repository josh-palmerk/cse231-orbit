/***********************************************************************
 * Source File:
 *    Main : Driving point for the program
 * Author:
 *    Garrin and Josh
 * Summary:
 *    Has main and calls callback to start the program.
 ************************************************************************/

#include <cassert>      // for ASSERT
#include <vector>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "test.h"
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include "spaceObject.h"
#include "satellite.h"
#include "hubble.h"

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {

      ptGPS.setMeters(0.0, 42164000.0);
	  velGPS.setDX(-3100.0);
      velGPS.setDY(0.0);

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
	  objects.push_back(new Hubble());
   }

   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;

   Velocity velGPS;

   vector<SpaceObject*> objects;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // Simulation time step (seconds per frame)
   
   //// 1. Get position
   //double xs = pDemo->ptGPS.getMetersX();
   //double ys = pDemo->ptGPS.getMetersY();

   //// 2. Compute gravity
   //const double g0 = 9.80665;         // m/s² at surface
   //const double rE = 6'378'000.0;     // Earth radius (m)

   //double r = sqrt(xs * xs + ys * ys);
   //double h = r - rE;
   //double gh = g0 * pow(rE / (rE + h), 2);

   //// 3. Compute direction toward Earth's center
   //Angle d;
   //d.setRadians(atan2(xs, ys));  // 0° = up in your system
   //d.add(M_PI);                  // reverse to point down (toward Earth)

   // 4. Decompose into components
   //double ddx = gh * sin(d.getRadians());
   //double ddy = gh * cos(d.getRadians());

   // 5. Apply acceleration to velocity (dv = a * dt)
   //Acceleration acc(ddx, ddy);
   //pDemo->velGPS.add(acc, dt);

   // 6. Update position using the new velocity (dx = v * dt)
   //pDemo->ptGPS.addMetersX(pDemo->velGPS.getDX() * dt);
   //pDemo->ptGPS.addMetersY(pDemo->velGPS.getDY() * dt);

   Position pt;
   ogstream gout(pt);
   const double dt = 48.0;

   for (auto obj : pDemo->objects)
   {
	   obj->updateObject(dt);
	   obj->draw(gout);
   }

   //
   // draw everything
   //

   // draw satellite
   //gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // rotate the earth
   pDemo->angleEarth += -150.8;
   pDemo->phaseStar++;
   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
