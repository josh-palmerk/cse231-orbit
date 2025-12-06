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
#include "simulator.h"

using namespace std;

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
   Simulator* pOrbit = (Simulator*)p;

   Position pt;
   ogstream gout(pt);
   const double dt = 48.0;

   vector<SpaceObject*>& spaceObjects = pOrbit->getSpaceObjects();
   vector<SpaceObject*> spaceObjectsCrashed;

   

   //cout << "spaceObjects.size() = " << spaceObjects.size() << endl;
   //cout << "sputnik position: " << spaceObjects[10]->getPosition() << endl;
   //cout << "dreamchaser positon: " << spaceObjects[11]->getPosition() << endl;
   //double distancebetween = computeDistance(spaceObjects[10]->getPosition(), spaceObjects[11]->getPosition());
   //cout << distancebetween << endl;

   if (spaceObjects.size() == 13)
   {
	   cout << "bullet position: " << spaceObjects[12]->getPosition() << endl;
	   cout << "earth position: " << spaceObjects[1]->getPosition() << endl;
	   cout << "dreamchaser positon: " << spaceObjects[11]->getPosition() << endl;
	   double distancebetween = computeDistance(spaceObjects[1]->getPosition(), spaceObjects[12]->getPosition());
	   cout << "distance between bullet and earth: " << distancebetween << endl;
   }

   

   for (int i = 0; i < spaceObjects.size(); i++)
   {
	   for (int x = i + 1; x < spaceObjects.size(); x++)
	   {
		   double distance = computeDistance(spaceObjects[i]->getPosition(), spaceObjects[x]->getPosition());

		   if (spaceObjects[i]->isDead() == false && spaceObjects[x]->isDead() == false)
		   {
			   if (distance < (spaceObjects[i]->getRadius() + spaceObjects[x]->getRadius()))
			   {
				   cout << "hello" << endl;
				   spaceObjects[i]->die();
				   spaceObjects[x]->die();
				   spaceObjectsCrashed.push_back(spaceObjects[i]);
				   spaceObjectsCrashed.push_back(spaceObjects[x]);
			   }
		   }
		   
	   }
   }

   //erase all crashed objects and add in the parts.
   for (auto obj : spaceObjectsCrashed)
   {
	   if (obj->isDead())
	   {
		   obj->shatter(spaceObjects);

	   }
   }

   //ai generated, get rid of the dead objects
   spaceObjects.erase(
	   remove_if(spaceObjects.begin(), spaceObjects.end(),
		   [](SpaceObject* obj) { return obj->isDead(); }),
	   spaceObjects.end()
    );


   //separate dream chaser logic
   pOrbit->getPlayer().handleInput(pUI, dt, spaceObjects);
   pOrbit->getPlayer().updateObject(dt, spaceObjects);
   pOrbit->getPlayer().draw(gout, pUI);

   //loop through each object
   /*for (auto obj : spaceObjects)
   {
	   obj->updateObject(dt, spaceObjects);
   }*/

   //draw
   for (auto obj : spaceObjects)
   {
	   //cout << obj->getRadius() << endl;
	   obj->updateObject(dt, spaceObjects);
	   obj->draw(gout);
   }

   //cout << endl;
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


   Simulator orbit;

   // set everything into action
   ui.run(callBack, &orbit);


   return 0;
}
