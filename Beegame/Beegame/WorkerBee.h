#pragma once
#include <SFML/Graphics.hpp>

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
};


 