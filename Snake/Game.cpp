#include "Game.h"
#include <iostream>
const unsigned WINDOW_WIDTH = 640;
const unsigned WINDOW_HEIGHT = 480;
const unsigned RECT_SIZE = 25;
Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My snake")
{
	directionX = 0;
	directionY = 0;
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
	tail[0].setCoordinates(1, 5);
	tail[1].setCoordinates(1, 4);
	tail[2].setCoordinates(1, 4);
	tail[3].setCoordinates(1, 3);
	tail[4].setCoordinates(2, 3);

	placeApple();
	score = 0;
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
		//sf::sleep(sf::milliseconds(100));
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
		std::cout << "Score: " << score << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (directionY != 1)
		{
			directionY = -1; // up
			directionX = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // right
	{
		if (directionX != -1)
		{
			directionX = 1;
			directionY = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // left 
	{
		if (directionX != 1)
		{
			directionX = -1;
			directionY = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // down
	{
		if (directionY != -1)
		{
			directionY = 1;
			directionX = 0;
		}
	}
}

void Game::update()
{
	if (directionX != 0 || directionY != 0) // check if it's moving
	{
		moveSnake();
	}
	
	for(int i = 0; i < tailLength; i++)
		matrix[tail[i].getX()][tail[i].getY()].setFillColor(sf::Color(100, 51, 153));
	matrix[head.getX()][head.getY()].setFillColor(sf::Color(153, 51, 153));
	matrix[applePosX][applePosY].setFillColor(sf::Color(255, 112, 77));
	sf::sleep(sf::milliseconds(100));
}

void Game::moveSnake()
{
	if (head.x + directionX == applePosX && head.y + directionY == applePosY)
	{
		eatApple();
	}
	else {
		matrix[tail[0].getX()][tail[0].getY()].setFillColor(sf::Color(128, 235, 138));
		for (int i = 0; i < tailLength - 1; i++)
		{
			tail[i].x = tail[i + 1].x;
			tail[i].y = tail[i + 1].y;
		}
		tail[tailLength - 1].x = head.x;
		tail[tailLength - 1].y = head.y;

		head.x += directionX;
		head.y += directionY;
		if (head.x < 0)
			head.x = MATRIX_SIZE - 1;
		if (head.x >= MATRIX_SIZE)
			head.x = 0;
		if (head.y < 0)
			head.y = MATRIX_SIZE - 1;
		if (head.y >= MATRIX_SIZE)
			head.y = 0;
	}
	if (collides())
	{
		std::cout << "Game over" << std::endl;
		sf::sleep(sf::milliseconds(800));
		window.close();
	}
}

void Game::eatApple()
{
	tail[tailLength].x = head.x;
	tail[tailLength].y = head.y;
	tailLength++;
	head.x = applePosX;
	head.y = applePosY;
	score += 10;
	placeApple();
}

void Game::placeApple()
{
	//matrix[applePosX][applePosY].setFillColor(sf::Color(128, 235, 138));
	applePosX = rand() % MATRIX_SIZE;
	applePosY = rand() % MATRIX_SIZE;
	//std::cout << "applepos: " << applePosX << ". " << applePosY << std::endl;
	if (head.getX() == applePosX && head.getY() == applePosY)
		placeApple();
	for (int i = 0; i < tailLength; i++)
	{
		if (tail[i].getX() == applePosX && tail[i].getY() == applePosY)
			placeApple();
	}
	
}

bool Game::collides()
{
	for (int i = 0; i < tailLength; i++)
	{
		if (head.getX() == tail[i].getX() && head.getY() == tail[i].getY())
		{
			return true;
		}
	}
	return false;
}

void Game::render()
{
	window.clear();
	for (int i = 0; i < MATRIX_SIZE; i++)
		for (int t = 0; t < MATRIX_SIZE; t++)
			window.draw(matrix[i][t]);
	window.display();
}