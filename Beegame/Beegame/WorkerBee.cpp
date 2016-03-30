#include "WorkerBee.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

WorkerBee::WorkerBee()
{
}


WorkerBee::~WorkerBee()
{
}


sf::CircleShape* WorkerBee::createWorkerB()
{
	
	sf::CircleShape* workerB;
	workerB = new sf::CircleShape(5);
	workerB->setFillColor(sf::Color::Yellow);
	workerB->setPosition(300, 300);
	

	return workerB;
}

