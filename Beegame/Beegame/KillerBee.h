#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Vektori2.h"

using namespace sf;

class KillerBee : public GameObject
{
public:

	

	KillerBee(std::string texturePath);
	~KillerBee();

	void Update(float dt) override;
	

private:
	float movementSpeed;
	std::vector<Vektori2*> waypoints;
	int currentWaypoint;
	int damage;
};

