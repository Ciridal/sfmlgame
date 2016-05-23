#include "KillerBee.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enemy.h"


KillerBee::KillerBee(std::string texturePath) 
	: GameObject(texturePath)
{
	
	movementSpeed = 200.0f;
	damage = 10;

}


KillerBee::~KillerBee()
{
	
}

void KillerBee::Update(float dt)
{
	if (Enemy::instance == nullptr)
		return;

	Vektori2 directionVector = Vektori2();
	Vektori2 targetPositionInPix = Enemy::instance->getPositionInPix();

	directionVector = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y);
	directionVector.Normalize();

	directionVector = directionVector * movementSpeed * dt;

	float distanceToTarget = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y).Magnitude();

	float directionVectorLength = directionVector.Magnitude();

	if (distanceToTarget < directionVectorLength)
	{
		Enemy::instance->takeDamage(damage);
		Game::instance->destroy(this);
	}

	sprite.setPosition(getPositionInPix().X + directionVector.X, getPositionInPix().Y + directionVector.Y);
}
