#include "Player.hpp"

void Player::CastRay(double rad)
{
}

bool Player::MapLoad(string path) {
	//	map.LoadMap(path, 10, 10);
	return true;
}

void Player::Move(bool isForward)
{
	int i = isForward ? 1 : -1;
	Forward.Rotate(radian);
	Location += Forward * Vector2D(move * i,move * i);
	Forward.Rotate(-radian);
	cout << "위치 : " << Location.x << " " << Location.y << endl;
	cout << "로테 : " << radian  << endl;
}

void Player::Rotate(double angle)
{
	double rad = CalcRad(angle);
	radian += rad;
	if (radian >= PI * 2) {
		radian -= PI * 2;
	}
	if (radian < 0) {
		radian += PI * 2;
	}
}

void Player::Draw(const int& width, const int& height)
{
	for (int i = 0; i < width; i++) {

	}
}
