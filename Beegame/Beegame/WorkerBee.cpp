#include "WorkerBee.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

WorkerBee::WorkerBee()
{
	workerB = CircleShape(5);
	workerB.setFillColor(Color::Yellow);
	workerB.setPosition(100, 500);
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
		window.draw(workerB);
		
	}
}
