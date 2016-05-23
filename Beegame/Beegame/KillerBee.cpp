#include "KillerBee.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


KillerBee::KillerBee(std::string texturePath) 
	: GameObject(texturePath)
{
	
	movementSpeed = 200.0f;
	waypoints = std::vector<Vektori2*>();

	waypoints.push_back(new Vektori2(800 * 0.9f, 600 * 0.8f));
	


	currentWaypoint = 0;


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
	Vektori2 directionVector = Vektori2();
	Vektori2 targetPositionInPix = *waypoints[currentWaypoint];

	directionVector = directionVector * movementSpeed * dt;

	float distanceToTarget = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y).Magnitude();

	float directionVectorLength = directionVector.Magnitude();

	if (distanceToTarget < directionVectorLength)
	{
		std::cout << "Waypoint " << currentWaypoint << " reached!" << std::endl;

		// change waypoint to next.
		currentWaypoint++;
		setScale(getScale().X * -1, getScale().Y);

		// if we have reached the last waypoint.
		if (currentWaypoint >= waypoints.size())
		{
			Game::instance->addHoney(0);
			Game::instance->destroy(this);
			// go to first waypoint
			currentWaypoint = 0;
		}
	}

	sprite.setPosition(getPositionInPix().X + directionVector.X, getPositionInPix().Y + directionVector.Y);
}
