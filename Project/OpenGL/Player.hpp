#pragma once
#include <string>

#include "Map.hpp"

using namespace std;

class Player {
private:
	double x, y;
	double radian;
	double move;
	double FOV;
	void CastRay(double rad);

	Map map;

public:
	

	bool MapLoad(string path);

	void Move();
	void Rotate(double rad);
	void Draw();

};