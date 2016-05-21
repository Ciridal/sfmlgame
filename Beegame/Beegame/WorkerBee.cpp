#include "WorkerBee.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"

WorkerBee::WorkerBee(std::string texturePath) 
	: GameObject(texturePath)
{
	movementSpeed = 180.0f;
	waypoints = std::vector<Vektori2*>();

	waypoints.push_back(new Vektori2(800*0.9f, 600*0.8f));
	waypoints.push_back(new Vektori2(800*0.1f, 600*0.8f));

	currentWaypoint = 0;
}


WorkerBee::~WorkerBee()
{
	for (Vektori2* waypoint : waypoints)
	{
		if (waypoint != nullptr)
		{
			delete waypoint;
		}
	}
}


void WorkerBee::Update(float dt)
{
	Vektori2 directionVector = Vektori2();
	Vektori2 targetPositionInPix = *waypoints[currentWaypoint];

	directionVector = Vektori2(targetPositionInPix.X - getPositionInPix().X, targetPositionInPix.Y - getPositionInPix().Y);
	directionVector.Normalize();

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
			Game::instance->addHoney(20);
			Game::instance->destroy(this);
			// go to first waypoint
			currentWaypoint = 0;
		}
	}

	sprite.setPosition(getPositionInPix().X + directionVector.X, getPositionInPix().Y + directionVector.Y);
}