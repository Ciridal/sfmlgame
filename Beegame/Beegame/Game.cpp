#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::update(float deltatime)
{

}

sf::RenderWindow Game::render()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Beekeeper");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();


		window.display();


	}


}