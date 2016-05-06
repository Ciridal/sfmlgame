#pragma once
#include <SFML/Graphics.hpp>
#include "Vektori2.h"

using namespace sf;

class WorkerBee 
{

public:

	CircleShape workerB;
	Texture workerTexture;

	WorkerBee();

	~WorkerBee();


	void Update(Clock& clock);
	void Draw(RenderWindow& window);

private:
	bool isClicked;

	float movementSpeed = 1.0f;

	Vektori2 m_position;

	std::vector<Vektori2*> waypoints;
	int currentWaypoint;

};


 