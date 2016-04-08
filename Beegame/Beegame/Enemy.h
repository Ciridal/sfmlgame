#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
public:

	RectangleShape enemy;

	Enemy();
	~Enemy();

	void Update(Clock& clock);
	void Draw(RenderWindow& window);
};

