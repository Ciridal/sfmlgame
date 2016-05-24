#include "Button.h"
#include "Game.h"
#include "GameManager.h"


Button::Button(std::string texturePath) 
	: GameObject(texturePath)
{
	state = Up;
}


Button::~Button()
{
}

void Button::Update(float dt)
{
	sf::Vector2i m_mousePosition = sf::Mouse::getPosition(*GameManager::window);
	

	bool mouseInButton = m_mousePosition.x >= getPositionInPix().X - getSprite().getGlobalBounds().width / 2
		&& m_mousePosition.x <= getPositionInPix().X + getSprite().getGlobalBounds().width / 2
		&& m_mousePosition.y >= getPositionInPix().Y - getSprite().getGlobalBounds().height / 2
		&& m_mousePosition.y <= getPositionInPix().Y + getSprite().getGlobalBounds().height / 2;
	
	if (Game::instance->event.type==sf::Event::MouseButtonPressed)
	{
		if (mouseInButton && state == Up)
		{
			state = Down;

			if (onClicked != nullptr)
			{
				(Game::instance->*onClicked)();
			}
		}
	}
	else if (Game::instance->event.type == sf::Event::MouseButtonReleased)
	{
		state = Up;
	}
	else if (Game::instance->event.type == sf::Event::MouseMoved)
	{
		if (mouseInButton == false)
		{
			state = Up;
		}
	}

	state == Down ? sprite.setColor(sf::Color::Red) : sprite.setColor(sf::Color::White);
}