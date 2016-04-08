#pragma once
#include "WorkerBee.h"
#include "KillerBee.h"
#include "Hive.h"
class GameObject
{
public:
	

	GameObject();
	~GameObject();

	void Update(Clock clock);
	void Draw(RenderWindow& window);
};

