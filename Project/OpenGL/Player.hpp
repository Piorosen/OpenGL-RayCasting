#pragma once
#include <string>

#include "Map.hpp"

#define PI 3.14159265358979323846264338327950288 

using namespace std;

class Player {
private:
	double x, y;
	double radian;
	double move;
	double FOV;
	void CastRay(double rad);

	Map map;

	double CalcRad(double angle) {
		return angle * (PI / 180.0);
	}

public:
	bool MapLoad(string path);

	void Move();
	void Rotate(double angle);
	void Draw();

};