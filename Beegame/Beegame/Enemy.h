#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h" 

using namespace sf;

class Enemy : public GameObject
{
public:

	

	Enemy(std::string texturePath);
	~Enemy();

	void Update(float dt);

};

