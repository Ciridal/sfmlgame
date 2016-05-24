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
	
	movementSpeed = 180.0f;
	reduceHoneyTime = 0.10f;
	reduceHoneyTimeRemaining = reduceHoneyTime;
}

Enemy* Enemy::instance = nullptr;

Enemy::~Enemy()
{
}

void Enemy::Update(float dt)
{
	if (Hive::instance == nullptr)
		return;

	Vektori2 directionVector = Vektori2();
	Vektori2 targetPositionInPix = Hive::instance->getPositionInPix();
	targetPositionInPix.X += 800 * 0.1f;

	directionVector = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y);
	directionVector.Normalize();

	directionVector = directionVector * movementSpeed * dt;

	float distanceToTarget = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y).Magnitude();

	float directionVectorLength = directionVector.Magnitude();

	if (distanceToTarget < directionVectorLength)
	{
		reduceHoneyTimeRemaining -= dt;
		if (reduceHoneyTimeRemaining <= 0.0f)
		{
			reduceHoneyTimeRemaining = reduceHoneyTime;
			Game::instance->reduceHoney(1);
		}
	}
	else
	{
		sprite.setPosition(getPositionInPix().X + directionVector.X, getPositionInPix().Y + directionVector.Y);
	}
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

	Game::instance->addScore(100);
	Enemy::instance = nullptr;
	Game::instance->destroy(this);
	
}