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

	waypoints = std::vector<Vektori2*>();

	waypoints.push_back(new Vektori2(800 * 0.14f + Game::instance->random(-0.005f, 0.005f), 600 * 0.8f + +Game::instance->random(-0.005f, 0.005f)));
	waypoints.push_back(new Vektori2(800 * 0.19f + Game::instance->random(-0.005f, 0.005f), 600 * 0.75f + Game::instance->random(-0.005f, 0.005f)));
	waypoints.push_back(new Vektori2(800 * 0.24f + Game::instance->random(-0.005f, 0.005f), 600 * 0.7f + Game::instance->random(-0.005f, 0.005f)));
	waypoints.push_back(new Vektori2(800 * 0.29f + Game::instance->random(-0.005f, 0.005f), 600 * 0.85f + Game::instance->random(-0.005f, 0.005f)));
	waypoints.push_back(new Vektori2(800 * 0.34f + Game::instance->random(-0.005f, 0.005f), 600 * 0.9f + Game::instance->random(-0.005f, 0.005f)));
	waypoints.push_back(new Vektori2(800 * 0.39f + Game::instance->random(-0.005f, 0.005f), 600 * 0.95f + Game::instance->random(-0.005f, 0.005f)));

	currentWaypoint = Game::instance->random(0, waypoints.size() - 1);
}


KillerBee::~KillerBee()
{
	for (Vektori2* waypoint : waypoints)
	{
		if (waypoint != nullptr)
		{
			delete waypoint;
		}
	}
}

void KillerBee::Update(float dt)
{
	bool enemyExists = Enemy::instance != nullptr;

	Vektori2 directionVector = Vektori2();
	Vektori2 targetPositionInPix = enemyExists == true ? Enemy::instance->getPositionInPix() : *waypoints[currentWaypoint];

	directionVector = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y);
	directionVector.Normalize();

	directionVector = directionVector * movementSpeed * dt;

	float distanceToTarget = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y).Magnitude();

	float directionVectorLength = directionVector.Magnitude();

	if (distanceToTarget < directionVectorLength)
	{
		if (enemyExists)
		{
			Enemy::instance->takeDamage(damage);
			Game::instance->destroy(this);
		}
		else
		{
			currentWaypoint = Game::instance->random(0, waypoints.size() - 1);
			
			Vektori2 directionVector = Vektori2();
			Vektori2 targetPositionInPix = *waypoints[currentWaypoint];

			directionVector = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y);
			directionVector.Normalize();
		}

		return;
	}

	float xScale = ((directionVector.X > 0.0f) && (getScale().X > 0)) || ((directionVector.X < 0.0f) && (getScale().X < 0)) ? getScale().X : getScale().X * -1;
	setScale(xScale, getScale().Y);

	sprite.setPosition(getPositionInPix().X + directionVector.X, getPositionInPix().Y + directionVector.Y);
}
