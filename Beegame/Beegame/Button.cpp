#include "Button.h"
#include "Game.h"


Button::Button(std::string texturePath) 
	: GameObject(texturePath)
{
	state = Down;
}


Button::~Button()
{
}

void Button::Update(float dt)
{
	sf::Vector2i m_mousePosition = sf::Mouse::getPosition(*Game::window);

}