#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class KillerBee : public GameObject
{
public:

	KillerBee(std::string texturePath);
	~KillerBee();

	void Update(float dt) override;

private:
	int damage;
	float movementSpeed;
	std::vector<Vektori2*> waypoints;
	int currentWaypoint;

};

