#include "Game.h"


Game::Game()
{
	window = new RenderWindow(VideoMode(800, 600), "Beekeeper");

	WorkerBee* workerB = Instantiate<WorkerBee>("..\\workerbeetexture.png");
	workerB->setScale(0.25f);
	workerB->setPosition(0.3f, 0.2f);

	KillerBee* killerB= Instantiate <KillerBee>("..\\killerbeetexture.png");
	killerB->setScale(0.25f);
	killerB -> setPosition(0.24f, 0.2f);

	Hive* hive = Instantiate <Hive>("..\\beehivetexture.png");
	hive->setScale(3);
	hive->setPosition(0.1f, 0.25f);

	Enemy* enemy = Instantiate <Enemy>("..\\enemytexture.png");
	enemy->setScale(0.5f);
	enemy->setPosition(0.9f, 0.25f);

	Button* workerButton = Instantiate <Button>("..\\workerbeebutton.png");
	workerButton->setPosition(0.07f, 0.06f);

	Button* killerButton = Instantiate <Button>("..\\killerbeebutton.png");
	killerButton->setPosition(0.2f, 0.06f);

	GameObject* background = Instantiate<GameObject>("..\\background.png");
	background->setPosition(0.5f, 0.5f);
	background->setRenderPriority(9000);

	GameObject* flowers = Instantiate<GameObject>("..\\flowers.png");
	flowers->setPosition(0.9f, 0.2f);

	std::sort(gameObjects.begin(), gameObjects.end(), GameObject::compareRenderPriority);
}


Game::~Game()
{
	for (GameObject* gameObject : gameObjects)
	{
		delete gameObject;
	}

}

RenderWindow* Game::window = nullptr;

void Game::Update()
{
	Clock clock;
	float deltaTime = 0.0f;



	while (window->isOpen())
	{


		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		for (GameObject* gameObject : gameObjects)
		{
			gameObject->Update(deltaTime);
		}

		Draw();
		
	}

	deltaTime = clock.restart().asSeconds();
}

void Game::Draw()
{
	window->clear(Color(135, 206, 255));
	
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw(*window);
	}

	window->display();
}