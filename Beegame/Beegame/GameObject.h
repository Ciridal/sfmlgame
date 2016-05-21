#pragma once
#include <SFML\Graphics.hpp>
#include "Vektori2.h"
#include <iostream>

class GameObject
{
public:
	

	GameObject(std::string texturePath, int renderPriority=0);
	~GameObject();

	static bool compareRenderPriority(const GameObject* lhs, const GameObject* rhs)
	{
		return lhs->renderPriority > rhs->renderPriority;
	}

	virtual void Update(float dt) {};
	virtual void Draw(sf::RenderWindow& window);

	Vektori2 getPosition();
	void setPosition(float X,float Y);

	Vektori2 getScale();
	void setScale(float X, float Y);
	void setScale(float sizeMultiplier);

	float getRotation();
	void setRotation(float angle);

	int getRenderPriority();
	void setRenderPriority(int priority);


private:

	int renderPriority;

	sf::Sprite sprite;
	sf::Texture texture;
};

