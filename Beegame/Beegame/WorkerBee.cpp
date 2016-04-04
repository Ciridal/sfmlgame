#include "WorkerBee.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

WorkerBee::WorkerBee()
{
	workerB = CircleShape(5);
	workerB.setFillColor(Color::Yellow);
}


WorkerBee::~WorkerBee()
{
}


void WorkerBee::Update(Clock& clock)
{
	
}

void WorkerBee::Draw(RenderWindow& window)
{
	window.draw(workerB);
}
