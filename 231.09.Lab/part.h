#pragma once
#include "spaceJunk.h"
#include <functional>

class Part : public SpaceJunk
{
public:
	Part();
	Part(const Position& pos, const Velocity& vel, const Angle& angle, double radius, std::function <void(const Position&, double)> drawFunction);
	void draw(ogstream& ui) const override;
private:
	std::function <void(const Position&, double)> drawFunction;
};
