#pragma once
#include <iostream>


class Vector2D {
public:
	double x, y;

public:
	Vector2D(double mx, double my) : x(mx), y(my) {}
	Vector2D() : x(0.0), y(0.0) {}
	Vector2D(const Vector2D& vec) : x(vec.x), y(vec.y) {}

	void operator+=(const Vector2D& other) {
		this->x += other.x;
		this->y += other.y;
	}
	Vector2D operator+(const Vector2D& other) const {
		return Vector2D(this->x + other.x, this->y + other.y);
	}

	void operator*=(const Vector2D& other) {
		this->x *= other.x;
		this->y *= other.y;
	}
	Vector2D operator*(const Vector2D& other) {
		return Vector2D(this->x * other.x, this->y * other.y);
	}

	void operator-=(const Vector2D& other) {
		this->x -= other.x;
		this->y -= other.y;
	}
	Vector2D operator-(const Vector2D& other) {
		return Vector2D(this->x - other.x, this->y - other.y);
	}

	static Vector2D Nomalize(Vector2D vec) {
		auto magnitude = Magnitude(vec);
		return Vector2D(vec.x / magnitude, vec.y / magnitude);
	}
	static float Distance(Vector2D x, Vector2D y) {
		return Magnitude(x - y);
	}
	static double Magnitude(Vector2D vec) {
		return sqrt(vec.x * vec.x + vec.y * vec.y);
	}
};