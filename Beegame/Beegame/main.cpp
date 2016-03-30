#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "WorkerBee.h"

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Beekeeper");
	
	WorkerBee workB;

	workB.createWorkerB();


	sf::Font font;
	if (!font.loadFromFile("..\\fontti.TTF"))
	{

	}

	sf::Text score;
	score.setFont(font);
	score.setString("Score:	");
	score.setCharacterSize(24);
	score.setColor(sf::Color::White);

	sf::Text honey;
	honey.setFont(font);
	honey.setString("Honey:	");
	honey.setCharacterSize(24);
	honey.setColor(sf::Color::White);
	honey.setPosition(0,26);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(score);
		window.draw(honey);
		
		window.display();
	}
	
	return 0;
}