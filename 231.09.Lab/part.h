#pragma once
#include "spaceJunk.h"
#include <functional>

class Part : public SpaceJunk
{
public:
	Part();
	Part(const Position& pos, const Velocity& vel, const Angle& angle, double radius, std::function <void(const Position&, double, const Position&)> drawFunction, int fragNum);
	void draw(ogstream& ui) const override;
	void shatter(vector<SpaceObject*>& spaceObjects);
private:
	std::function <void(const Position&, double, const Position&)> drawFunction;
	int fragNum; // number of fragments made when shattered
};
