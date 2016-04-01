#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <iostream>
#include <string>

class Button
{
public:
	Button(sf::Image* normal, sf::Image* clicked, std::string, sf::Vector2f location);
	~Button();

	void checkClick(sf::Vector2f);
	void setState(bool);
	void setText(std::string);
	bool getVar();
	sf::Sprite* getSprite();
	sf::String * getText();

private:

	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite* currentSpr;
	sf::String String;
	bool current;
};

