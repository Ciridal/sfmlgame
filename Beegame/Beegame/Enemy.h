#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h" 

using namespace sf;

class Enemy : public GameObject
{
public:
	static Enemy* instance;

	Enemy(std::string texturePath);
	~Enemy();

	void Update(float dt);
	void setHealth(int amount);
	void takeDamage(int amount);

	void kill();

private:

	int health;
	float movementSpeed;
	void die();


	float reduceHoneyTime;
	float reduceHoneyTimeRemaining;
};

