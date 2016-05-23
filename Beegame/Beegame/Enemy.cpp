#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(std::string texturePath) 
	: GameObject (texturePath)
{
	if (Enemy::instance == nullptr)
		instance = this;
	else
		throw "Enemy exists";

	health = 100;
	damage = 100;
}

Enemy* Enemy::instance = nullptr;

Enemy::~Enemy()
{
}

void Enemy::Update(float dt)
{

}

void Enemy::setHealth(int amount)
{
	health = amount;

	if (health <= 0)
	{
		die();
	}
}

void Enemy::takeDamage(int amount)
{
	health = health - amount;

	if (health <= 0)
	{
		die();
	}
}

void Enemy::kill()
{
	die();
}

void Enemy::die()
{
	Enemy::instance = nullptr;
	Game::instance->destroy(this);
}