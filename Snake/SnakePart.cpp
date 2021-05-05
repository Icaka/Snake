#include "SnakePart.h"

SnakePart::SnakePart() : x(0), y(0)
{
}

SnakePart::SnakePart(int xPos, int yPos)
{
	x = xPos;
	y = yPos;
}

void SnakePart::setCoordinates(int xPos, int yPos)
{
	x = xPos;
	y = yPos;
}

int SnakePart::getX() const
{
	return x;
}

int SnakePart::getY() const
{
	return y;
}