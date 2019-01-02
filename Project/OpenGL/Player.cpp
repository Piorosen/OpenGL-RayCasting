#include "Player.hpp"


bool Player::MapLoad(string path) {
	map.LoadMap(path, 10, 10);
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
	for (int x = 0; x < width; x++)
	{
		// Where on the screen the ray goes through
		double rayScreenPos = (-RENDER_WIDTH / 2 + x);

		// The distance from the viewer to the point on the screen
		double rayViewDist = sqrt((rayScreenPos * rayScreenPos) + (viewDist * viewDist));

		// The angle of the ray, relative to the viewing direction.
		double rayAngle = asin(rayScreenPos / rayViewDist);

		CastRay(playerRot + rayAngle, x);
	}
}

void Player::CastRay(double rad)
{
}