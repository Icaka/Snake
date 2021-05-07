#pragma once
#include <SFML/Graphics.hpp>
#include "SnakePart.h"
const int MATRIX_SIZE = 15;

class Game
{
private:
	sf::RenderWindow window;
	sf::RectangleShape matrix[MATRIX_SIZE][MATRIX_SIZE];
	SnakePart head;
	int tailLength = 2;
	SnakePart tail[2];
	//Snake snake;
	int directionX = 0;
	int directionY = 0;
protected:
	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key);
	void moveSnake();
public:
	Game();
	void run();
};