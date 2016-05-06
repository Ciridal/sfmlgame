#include "WorkerBee.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

WorkerBee::WorkerBee()
{
	workerB = CircleShape(50);

	workerB.setPosition(100, 400);
	isClicked = false;

	if (!workerTexture.loadFromFile("..\\workerbeetexture.png"))
	{
		
	}

	workerB.setTexture(&workerTexture);
	
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


void WorkerBee::Update(Clock& clock)
{
	Vektori2 directionVector = Vektori2();
	Vektori2 targetPosition = *waypoints[currentWaypoint];

	directionVector = Vektori2(targetPosition.X - m_position.X, targetPosition.Y - m_position.Y);
	directionVector.Normalize();

	directionVector = directionVector * movementSpeed * clock;

	float distanceToTarget = Vektori2(targetPosition.X - m_position.X, targetPosition.Y - m_position.Y);
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

void WorkerBee::Draw(RenderWindow& window)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		isClicked = true;
	}
	if (isClicked)
	{
		window.draw(workerB);
		
	}
}
