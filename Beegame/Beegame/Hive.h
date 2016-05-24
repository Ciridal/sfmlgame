#pragma once
#include <SFML/Graphics.hpp>
#include "Vektori2.h"
#include "GameObject.h"

using namespace sf;

class Hive : public GameObject
{
public:
	
	static Hive* instance;

	Hive(std::string texturePath);
	~Hive();

	
	void Update(float dt) override;

	void takeDamage(int amount);
	void setHealth(int amount);
	void kill();

private:
	
	int health;
	void die();
};

