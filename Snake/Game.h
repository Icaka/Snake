#pragma once
#include <SFML/Graphics.hpp>

const int MATRIX_SIZE = 10;

class Game
{
private:
	sf::RenderWindow window;
	sf::RectangleShape matrix[MATRIX_SIZE][MATRIX_SIZE];

	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key);
public:
	Game();
	void run();
};