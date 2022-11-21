#pragma once
#include <array>

//class of a single game figure
class Figure {
protected:
	//array of grid of value
	std::array<std::array<bool, 4>, 4> value;
public:
	Figure(const Figure& figure);
	Figure(std::array<std::array<bool, 4>, 4> _value);

	//gets needed element with (x;y) coords
	bool& get(int x, int y);

	//prints figure in console
	void display();
};