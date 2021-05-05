#pragma once

struct SnakePart
{
	int x;
	int y;
	SnakePart();
	SnakePart(const int, const int);
	void setCoordinates(int, int);
	int getX() const;
	int getY() const;
};