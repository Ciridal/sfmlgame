#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"


using namespace sf;

class Game
{
public:


	RenderWindow* window;
	WorkerBee* workerB;
	Clock clock;

	Game();
	~Game();

	void Update();
	void Draw();

private:


};

