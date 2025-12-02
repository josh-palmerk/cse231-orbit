#include "fragment.h"


/***********************************************
* FRAGMENT : Default Constructor
* 	   Creates the fragment object
* ***********************************************/
Fragment::Fragment()
	: SpaceJunk()
{
}
/***********************************************
* FRAGMENT : NonDefault Constructor
* 	   Creates a fragment object
* ***********************************************/
	
Fragment::Fragment(const Position& pos, const Velocity& vel, const Angle& angle, double radius)
	: SpaceJunk(pos, vel, angle, radius)
{
	radius = 2; // radius of Fragment in pixels
	addKick();
}

/***********************************************
* FRAGMENT : Draw
* 	   Draws the fragment object
* ***********************************************/
void Fragment::draw(ogstream& ui) const
{
	// Drawing logic for Fragment
	ui.drawFragment(getPosition(), getAngle().getRadians());
}


/***********************************************
* FRAGMENT : Update Object
*         Updates the fragment object
* ***********************************************/
void Fragment::updateObject(double timestep, vector<SpaceObject*>& spaceObjects)
{
	// Call the base class updateObject to handle position update
	SpaceJunk::updateObject(timestep, spaceObjects);
	// Additional logic for Fragment can be added here if needed
	rotate(timestep * 1.5); // Fragments rotate wildly
}