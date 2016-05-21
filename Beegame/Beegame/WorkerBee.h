#pragma once
#include <SFML/Graphics.hpp>
#include "Vektori2.h"
#include "GameObject.h"

using namespace sf;

class WorkerBee : public GameObject
{

public:

	CircleShape workerB;
	Texture workerTexture;

	WorkerBee(std::string texturePath);

	~WorkerBee();

	void Update(float dt) override;

private:
	bool isClicked;

	float movementSpeed = 1.0f;

	Vektori2 m_position;

	std::vector<Vektori2*> waypoints;
	int currentWaypoint;

};


 