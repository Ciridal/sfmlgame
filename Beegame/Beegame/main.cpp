#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.h"

int main()
{
	
	Game gaem;

	gaem.render();

	
	return 0;
}

























/*
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
honey.setPosition(0,26);*/