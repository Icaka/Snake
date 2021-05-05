#include "Game.h"

const unsigned WINDOW_WIDTH = 640;
const unsigned WINDOW_HEIGHT = 480;
const unsigned RECT_SIZE = 25;
Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My snakw")
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int t = 0; t < MATRIX_SIZE; t++)
		{
			matrix[i][t].setSize(sf::Vector2f(RECT_SIZE, RECT_SIZE));
			
			matrix[i][t].setFillColor(sf::Color(128, 235, 138));
			matrix[i][t].setOutlineThickness(1);
			matrix[i][t].setOutlineColor(sf::Color::Black);
			matrix[i][t].setPosition(sf::Vector2f(i * RECT_SIZE, t * RECT_SIZE));
		}
	}

	head.setCoordinates(3, 3);
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			handlePlayerInput(event.key.code);
		}
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::X)
	{
		window.close();
	}
}

void Game::update()
{
	matrix[head.getX()][head.getY()].setFillColor(sf::Color(153, 51, 153));
}

void Game::render()
{
	window.clear();
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int t = 0; t < MATRIX_SIZE; t++)
			window.draw(matrix[i][t]);
	window.display();
}