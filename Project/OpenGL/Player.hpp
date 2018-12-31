#pragma once
#include <string>

#include "Map.hpp"
#include "Vector2D.hpp"

#define PI 3.14159265358979323846264338327950288 

using namespace std;

class Player {
private:
	Vector2D Forward;
	Vector2D Location;
	double radian;
	double move;
	double FOV;
	void CastRay(double rad);

	Map map;

	double CalcRad(double angle) {
		return angle * (PI / 180.0);
	}

public:
	Player() {
		Forward = std::move(Vector2D(1, 0));
		move = 1;
	}

	bool MapLoad(string path);

	void Move(bool isForward);
	void Rotate(double angle);
	void Draw(const int& width, const int& height);

};