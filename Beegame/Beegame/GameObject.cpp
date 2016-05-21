#include "GameObject.h"
#include "Game.h"


GameObject::GameObject(std::string texturePath,int renderPriority)
{
	if (!texture.loadFromFile(texturePath))
	{
		throw "Failed to load texture: " + texturePath;
	}

	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x * 0.5f, texture.getSize().y * 0.5f);

	setRenderPriority(renderPriority);
}

GameObject::~GameObject()
{
}

Vektori2 GameObject::getPosition()
{
	return Vektori2(sprite.getPosition().x / Game::window->getSize().x, sprite.getPosition().y / Game::window->getSize().y);
}

void GameObject::setPosition(float X, float Y)
{
	Y = 1.0f - Y;
	sprite.setPosition(Game::window->getSize().x * X, Game::window->getSize().y * Y);
}

void GameObject::Draw(sf::RenderWindow& window)
{
		window.draw(sprite);
}

Vektori2 GameObject::getScale()
{
	return sprite.getScale();
}

void GameObject::setScale(float X, float Y)
{
	sprite.setScale(X, Y);
}

void GameObject::setScale(float sizeMultiplier)
{
	setScale(sizeMultiplier, sizeMultiplier);
}

float GameObject::getRotation()
{
	return sprite.getRotation();
}

void GameObject::setRotation(float angle)
{
	sprite.setRotation(angle);
}

int GameObject::getRenderPriority()
{
	return renderPriority;
}

void GameObject::setRenderPriority(int priority)
{
	renderPriority = priority;
}