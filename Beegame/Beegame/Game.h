#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Game
{
public:
	Game();
	~Game();

	void update(float deltatime);



private:

	std::vector<GameObject>gameObjects;
};

