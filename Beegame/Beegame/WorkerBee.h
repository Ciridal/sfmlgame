#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class WorkerBee
{

public:

	CircleShape workerB;

	WorkerBee();

	~WorkerBee();

	void Update(Clock& clock);
	void Draw(RenderWindow& window);

private:

};


 