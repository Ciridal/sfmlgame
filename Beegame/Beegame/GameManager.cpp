#include "GameManager.h"



GameManager::GameManager()
{
	window = new RenderWindow(VideoMode(800, 600), "Beekeeper");
	game = new Game();
}


GameManager::~GameManager()
{
	delete game;
	delete window;
}


Scene* GameManager::activeScene = nullptr;
Game* GameManager::game = nullptr;
sf::RenderWindow* GameManager::window = nullptr;

void GameManager::Run()
{
	Clock clock;
	float deltaTime = 0.0f;

	ChangeScene(game);

	while (window->isOpen())
	{
		while (window->pollEvent(Game::instance->event))
		{
			if (Game::instance->event.type == Event::Closed)
				window->close();
		}

		deltaTime = clock.restart().asSeconds();
		activeScene->Update(deltaTime);
		activeScene->Draw(*window);
	}

	delete game;
	delete window;
}
