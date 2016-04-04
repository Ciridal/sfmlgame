#include "Game.h"


Game::Game()
{
	window = new RenderWindow(VideoMode(800, 600), "Beekeeper");
	workerB = new WorkerBee();
	
}


Game::~Game()
{
	delete workerB;
	delete window;
}

void Game::Update()
{
	while (window->isOpen())
	{


		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		workerB->Update(clock);

		Draw();
		clock.restart();
	}

}

void Game::Draw()
{
	window->clear(Color(135, 206, 255));
	workerB->Draw(*window);
	window->display();
}