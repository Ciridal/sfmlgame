#pragma once
#include <SFML/Graphics.hpp>
#include "Vektori2.h"
#include "GameObject.h"

using namespace sf;

class WorkerBee : public GameObject
{

public:
	WorkerBee(std::string texturePath);
	~WorkerBee();

	void Update(float dt) override;

private:

	float movementSpeed;
	std::vector<Vektori2*> waypoints;


	int currentWaypoint;

};


 