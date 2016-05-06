#include "Game.h"


Game::Game()
{
	window = new RenderWindow(VideoMode(800, 600), "Beekeeper");
	workerB = new WorkerBee();
	killerB = new KillerBee();
	hive = new Hive();
	points = new Hive();
	honey = new Hive();
	enemy = new Enemy();
}


Game::~Game()
{
	delete hive;
	delete killerB;
	delete workerB;
	delete window;
	delete points;
	delete honey;
	delete enemy;
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
		killerB->Update(clock);
		hive->Update(clock);
		enemy->Update(clock);

		Draw();
		clock.restart();
	}

}

void Game::Draw()
{
	window->clear(Color(135, 206, 255));
	hive->Draw(*window);
	workerB->Draw(*window);
	killerB -> Draw(*window);
	points->Draw(*window);
	honey->Draw(*window);
	enemy -> Draw(*window);
	window->display();
}