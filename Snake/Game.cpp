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
	tail[0].setCoordinates(1, 3);
	tail[1].setCoordinates(2, 3);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		directionY = -1; // up
		directionX = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // right
	{
		directionX = 1;
		directionY = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // left 
	{
		directionX = -1;
		directionY = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // down
	{
		directionY = 1;
		directionX = 0;
	}
}

void Game::update()
{
	if (directionX != 0 || directionY != 0) // check if it's moving
	{
		matrix[tail[0].getX()][tail[0].getY()].setFillColor(sf::Color(128, 235, 138));
		for (int i = 0; i < tailLength - 1; i++)
		{
			tail[i].x = tail[i + 1].x;
			tail[i].y = tail[i + 1].y;
		}
		tail[tailLength - 1].x = head.x;
		tail[tailLength - 1].y = head.y;
	}
	head.x += directionX;
	head.y += directionY;
	//snake.drawToMatrix(matrix);
	for(int i = 0; i < tailLength; i++)
		matrix[tail[i].getX()][tail[i].getY()].setFillColor(sf::Color(100, 51, 153));
	matrix[head.getX()][head.getY()].setFillColor(sf::Color(153, 51, 153));
	sf::sleep(sf::milliseconds(100));
}

void Game::render()
{
	window.clear();
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int t = 0; t < MATRIX_SIZE; t++)
			window.draw(matrix[i][t]);
	window.display();
}