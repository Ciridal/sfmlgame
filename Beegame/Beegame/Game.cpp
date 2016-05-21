#include "Game.h"
#include "Button.h"

Game::Game()
{
	if (instance != nullptr)
		return;

	instance = this;

	window = new RenderWindow(VideoMode(800, 600), "Beekeeper");


	Hive* hive = Instantiate <Hive>("..\\beehivetexture.png");
	hive->setScale(3);
	hive->setPosition(0.1f, 0.25f);

	Enemy* enemy = Instantiate <Enemy>("..\\enemytexture.png");
	enemy->setScale(0.5f);
	enemy->setPosition(0.9f, 0.25f);

	Button* workerButton = Instantiate <Button>("..\\workerbeebutton.png");
	workerButton->setPosition(0.07f, 0.06f);
	workerButton->onClicked = &Game::spawnWorkerBee;


	Button* killerButton = Instantiate <Button>("..\\killerbeebutton.png");
	killerButton->setPosition(0.2f, 0.06f);
	killerButton->onClicked = &Game::spawnKillerBee;

	GameObject* background = Instantiate<GameObject>("..\\background.png");
	background->setPosition(0.5f, 0.5f);
	background->setRenderPriority(9000);

	GameObject* flowers = Instantiate<GameObject>("..\\flowers.png");
	flowers->setPosition(0.9f, 0.2f);

	

	if (!font.loadFromFile("..\\fontti.TTF"))
	{
		throw "Unable to load font";
	}

	score.setFont(font);
	score.setCharacterSize(30);
	score.setColor(Color::White);
	score.setPosition(4, 4);

	honey.setFont(font);
	honey.setCharacterSize(30);
	honey.setColor(Color::White);
	honey.setPosition(4, 38);

	setScore(0);
	setHoney(10000);
}


Game::~Game()
{
	for (GameObject* gameObject : gameObjects)
	{
		delete gameObject;
	}

}

Game* Game::instance = nullptr;

void Game::Update()
{
	Clock clock;
	float deltaTime = 0.0f;

	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		deltaTime = clock.restart().asSeconds();
		for (GameObject* gameObject : gameObjects)
		{
			gameObject->Update(deltaTime);
		}

		updateGameObjectList();

		Draw();
	}
}

void Game::Draw()
{
	window->clear(Color(135, 206, 255));
	
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw(*window);
		
	}
	window->draw(score);
	window->draw(honey);

	window->display();
}

void Game::setHoney(int honeyAmount)
{
	this->honeyAmount = honeyAmount;
	honey.setString("Honey	" + std::to_string(honeyAmount));
}

void Game::addHoney(int honeyAmount)
{
	setHoney(this->honeyAmount + honeyAmount);
}

void Game::setScore(int scoreAmount)
{
	this->scoreAmount = scoreAmount;
	score.setString("Score	 " + std::to_string(scoreAmount));

}

void Game::spawnWorkerBee()
{
	if (honeyAmount >= 10)
	{
		setHoney(honeyAmount - 10);

		WorkerBee* workerB = Instantiate<WorkerBee>("..\\workerbeetexture.png");
		workerB->setScale(0.25f);
		workerB->setPosition(0.1f, 0.2f);
	}
}

void Game::spawnKillerBee()
{
	if (honeyAmount >= 50)
	{
		setHoney(honeyAmount - 50);

		KillerBee* killerB = Instantiate <KillerBee>("..\\killerbeetexture.png");
		killerB->setScale(0.25f);
		killerB->setPosition(0.24f, 0.2f);
	}
}

void Game::updateGameObjectList()
{
	while (destroyObjects.size() > 0)
	{
		std::vector<GameObject*>::iterator iter = std::find(gameObjects.begin(), gameObjects.end(), destroyObjects.at(0));
		if (iter != gameObjects.end())
		{
			gameObjects.erase(iter);
			destroyObjects.erase(destroyObjects.begin());
		}
	}

	bool requiresSort = newGameObjects.size() > 0;
	while (newGameObjects.size() > 0)
	{
		gameObjects.push_back(newGameObjects.at(0));
		newGameObjects.erase(newGameObjects.begin());
	}

	if(requiresSort)
		std::sort(gameObjects.begin(), gameObjects.end(), GameObject::compareRenderPriority);
}

void Game::destroy(GameObject* gameObject)
{
	destroyObjects.push_back(gameObject);
}