#pragma once
#include "spaceObject.h"
#include "uiDraw.h"
#include "uiInteract.h" // for INTERFACE

class TestDreamChaser;

class DreamChaser : public SpaceObject
{
public:

	friend TestDreamChaser;

	DreamChaser();
	DreamChaser(const Position& pos, const Velocity& vel, const Angle& angle, double radius);

	//using SpaceObject::draw;
	void draw(ogstream& ui) const override {} // to satisfy pure virtual requirement
	void draw(ogstream& ui, const Interface* pUI) const;
	
	// Specifics for DreamChaser
	void fireBullet();
	void addThrust(double timestep); //might need to take amount

	//void updateObject(double timestep) override;
	void handleInput(const Interface* pUI, double timestep);
};

