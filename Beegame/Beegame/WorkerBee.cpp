#include "WorkerBee.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

WorkerBee::WorkerBee(std::string texturePath) 
	: GameObject(texturePath)
{
	workerB.setPosition(100, 400);
	isClicked = false;
	
	movementSpeed = 180.0f;
	waypoints = std::vector<Vektori2*>();

	waypoints.push_back(new Vektori2(100, 100));

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
	Vektori2 targetPosition = *waypoints[currentWaypoint];

	directionVector = Vektori2(targetPosition.X - m_position.X, targetPosition.Y - m_position.Y);
	directionVector.Normalize();

	directionVector = directionVector * movementSpeed * dt;

	float distanceToTarget = Vektori2(targetPosition.X - m_position.X, targetPosition.Y - m_position.Y).Magnitude();
	float directionVectorLength = directionVector.Magnitude();

	if (distanceToTarget < directionVectorLength)
	{
		std::cout << "DistanceToTarget: " << distanceToTarget << " DirectionVectorLen: " << directionVectorLength << std::endl;

		// change waypoint to next.
		currentWaypoint++;

		// if we have reached the last waypoint.
		if (currentWaypoint >= waypoints.size())
		{
			// go to first waypoint
			currentWaypoint = 0;
		}
	}
	m_position += directionVector;
}