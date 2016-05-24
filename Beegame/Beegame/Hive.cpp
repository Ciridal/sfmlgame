#include "Hive.h"
#include "Game.h"


Hive::Hive(std::string texturePath) 
	: GameObject(texturePath)
{
	if (instance == nullptr)
		instance = this;
	else
		throw "Hive exists";

	health = 500;
}


Hive::~Hive()
{

}

Hive* Hive::instance = nullptr;

void Hive::Update(float dt)
{

}

void Hive::takeDamage(int amount)
{
	health -= amount;
}

void Hive::setHealth(int amount)
{
	health = amount;
}

void Hive::kill()
{
	die();
}

void Hive::die()
{
	instance = nullptr;
	Game::instance->destroy(this);
}