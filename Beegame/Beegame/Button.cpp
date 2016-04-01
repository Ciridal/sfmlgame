#include "Button.h"


Button::Button(sf::Image* normal, sf::Image* clicked, std::string, sf::Vector2f location)
{
	this->normal.setImage(*normal);
	this->clicked.setImage(*clicked);
	this->currentSpr = &this->normal;
	current = false;
	this->normal.setPosition(location);
	this->clicked.setPosition(location);
	String.setText(words);
	String.setPosition(location.x + 3, location.y + 3);
	String.setSize(14);
}


Button::~Button()
{
}

void Button::checkClick(sf::Vector2f mousePos) 
{
	if (mousePos.x>currentSpr->getPosition().x && mousePos.x<(currentSpr->getPosition().x + currentSpr->getSize().x))
	{
		if (mousePos.y>currentSpr->getPosition().y && mousePos.y<(currentSpr->getPosition().y + currentSpr->getSize().y)) 
		{
			setState(!current);
		}
	}
}

void Button::setState(bool which)
{
	current = which;
	if (current) 
	{
		currentSpr = &clicked;
		return;
	}
	currentSpr = &normal;
}

void Button::setText(std::string words) 
{
	String.setText(words);
}

bool Button::getVar() 
{
	return current;
}

sf::Sprite* Button::getSprite() 
{
	return currentSpr;
}

sf::String * Button::getText() 
{
	return &String;
}