#pragma once
#include <string>

#include "Map.hpp"
#include "Vector2D.hpp"

#define PI 3.14159265358979323846264338327950288 
#define TWO_PI (PI * 2)

using namespace std;

class Player {
private:
	Vector2D Forward;
	Vector2D Location;
	double playerRot;
	double move;
	double FOV;
	int MapX, MapY;
	double viewDist;

	Map map;

	double CalcRad(double angle) {
		return angle * (PI / 180.0);
	}

	void CastRay(double rad, int x);

	void DrawLine(int x, double Height, int tile);

public:
	Player(int x, int y) {
		Forward = std::move(Vector2D(1, 0));
		Location.x = x;
		Location.y = y;
		FOV = CalcRad(90);
		move = 1;
	}

	bool MapLoad(string path);
	void Move(bool isForward);
	void Rotate(double angle);
	void Draw(const int& width, const int& height);

};