#pragma once

using byte = unsigned char;

class Color
{
public:
	Color() {
		red = 0;
		green = 0;
		blue = 0;
		alpha = 0;
	}
	Color(const byte& red, const byte& green, const byte& blue) 
		: red(red)
		, green(green)
		, blue(blue)
		, alpha(255)
	{}

	Color(const byte& red, const byte& green, const byte& blue, const byte& alpha)
		: red(red)
		, green(green)
		, blue(blue)
		, alpha(alpha)
	{}

	byte red;
	byte green;
	byte blue;
	byte alpha;
};