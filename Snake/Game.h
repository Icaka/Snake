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

	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key);
public:
	Game();
	void run();
};