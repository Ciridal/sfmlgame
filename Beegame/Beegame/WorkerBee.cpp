#include "WorkerBee.h"


WorkerBee::WorkerBee()
{
}


WorkerBee::~WorkerBee()
{
}


sf::CircleShape WorkerBee::createBee()
{
	

	sf::CircleShape workerBee(5);
	workerBee.setFillColor(sf::Color::Yellow);
	workerBee.setPosition(300, 300);
	

	return workerBee;
}

void WorkerBee::drawBee()
{
	
	
}