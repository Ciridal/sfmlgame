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
}


WorkerBee::~WorkerBee()
{
}


void WorkerBee::Update(Clock& clock)
{
	
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
