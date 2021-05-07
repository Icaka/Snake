#pragma once
#include <SFML/Graphics.hpp>
#include "SnakePart.h"
const int MATRIX_SIZE = 15;
const int STARTING_TAIL = 5;
class Game
{
private:
	sf::RenderWindow window;
	sf::RectangleShape matrix[MATRIX_SIZE][MATRIX_SIZE];
	SnakePart head;
	int tailLength = STARTING_TAIL;
	SnakePart tail[STARTING_TAIL];
	//Snake snake;
	int directionX;
	int directionY;
	int applePosX;
	int applePosY;

	int score;
protected:
	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key);
	void moveSnake();
	void placeApple();
public:
	Game();
	void run();
};