#pragma once
#include <SFML/Graphics.hpp>
class Game
{
private:
	sf::RenderWindow window;
	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key);
public:
	Game();
	void run();
};