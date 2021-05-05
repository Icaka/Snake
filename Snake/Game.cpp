#include "Game.h"

const unsigned WINDOW_WIDTH = 640;
const unsigned WINDOW_HEIGHT = 480;

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My snakw")
{
	
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
			//handlePlayerInput(event.key.code);
		}
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Game::update()
{

}

void Game::render()
{
	window.clear();

	window.display();
}