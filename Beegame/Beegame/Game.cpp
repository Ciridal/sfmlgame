#include "Game.h"
#include "Button.h"
#include <stdlib.h>

Game::Game()
{
	if (instance != nullptr)
		return;

	instance = this;
	pendingRestart = false;
	srand(time(NULL));

	gameOverScore = nullptr;
	honey = nullptr;
	score = nullptr;

	restart();
}


Game::~Game()
{
}

Game* Game::instance = nullptr;

void Game::Update(float dt)
{
	if (pendingRestart)
	{
		pendingRestart = false;
		restart();
	}

	Scene::Update(dt);

	if (Enemy::instance == nullptr)
	{
		enemySpawnTimeRemaining -= dt;
		if (enemySpawnTimeRemaining <= 0.0f)
		{
			spawnEnemy();
		}
	}
}

void Game::cleanUp()
{
	Scene::cleanUp();
	
	if (honey != nullptr)
		delete honey;

	if (score != nullptr)
		delete score;

	if (gameOverScore != nullptr)
		delete gameOverScore;
}

void Game::Draw(sf::RenderWindow& window)
{
	window.clear(sf::Color(135, 206, 255));

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw(window);
	}

	window.draw(*score);
	window.draw(*honey);

	window.display();
}

void Game::setHoney(int honeyAmount)
{
	this->honeyAmount = honeyAmount;
	honey->setString("Honey	" + std::to_string(honeyAmount));

	if (this->honeyAmount <= 0)
	{
		this->honeyAmount = 0;

		if (Hive::instance != nullptr)
		{
			Hive::instance->kill();
			gameOver();
		}
	}
}

void Game::addHoney(int honeyAmount)
{
	setHoney(this->honeyAmount + honeyAmount);
}

void Game::reduceHoney(int amount)
{
	setHoney(honeyAmount - amount);
}

void Game::setScore(int scoreAmount)
{
	this->scoreAmount = scoreAmount;
	score->setString("Score	 " + std::to_string(scoreAmount));
}

void Game::addScore(int scoreAmount)
{
	setScore(this->scoreAmount + scoreAmount);
}

void Game::spawnWorkerBee()
{
	if (honeyAmount >= 10)
	{
		setHoney(honeyAmount - 10);

		WorkerBee* workerB = Instantiate<WorkerBee>("..\\workerbeetexture.png");
		workerB->setScale(0.25f);
		workerB->setPosition(0.1f, 0.2f);
		workerB->setRenderPriority(random(0, 4000));
	}
}

void Game::spawnKillerBee()
{
	if (honeyAmount >= 20)
	{
		setHoney(honeyAmount - 20);

		KillerBee* killerB = Instantiate <KillerBee>("..\\killerbeetexture.png");
		killerB->setScale(0.25f);
		killerB->setPosition(0.24f, 0.2f);
		killerB->setRenderPriority(random(0, 4000));
	}
}

void Game::spawnEnemy()
{
	enemySpawnTime = random(5.0f, 15.0f);
	enemySpawnTimeRemaining = enemySpawnTime;

	Enemy* enemy = Instantiate <Enemy>("..\\enemytexture.png");
	enemy->setScale(0.5f);
	enemy->setPosition(0.9f, 0.25f);
	enemy->setRenderPriority(7000);
}

int Game::random(int minValue, int maxValue)
{
	return rand() % maxValue + minValue;
}

float Game::random(float minValue, float maxValue)
{
	float r = ((float)rand()) / (float)RAND_MAX;

	float range = maxValue - minValue;

	return (r*range) + minValue;
}

void Game::gameOver()
{
	GameObject* gameOverScreen = Instantiate <GameObject>("..\\gameoverscene.png");
	gameOverScreen->setRenderPriority(1);
	gameOverScreen->setPosition(0.5f, 0.5f);

	Button* gameOverRestartButton = Instantiate <Button>("..\\restartbutton.png");
	gameOverRestartButton->setRenderPriority(0);
	gameOverRestartButton->setPosition(0.5f, 0.4f);
	gameOverRestartButton->onClicked = &Game::restartClicked;
	
	gameOverScore->setString("Score: " + std::to_string(scoreAmount));
}

void Game::restartClicked()
{
	pendingRestart = true;
}

void Game::restart()
{
	cleanUp();

	Hive* hive = Instantiate <Hive>("..\\beehivetexture.png");
	hive->setScale(3);
	hive->setPosition(0.1f, 0.25f);
	hive->setRenderPriority(8000);

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
	flowers->setRenderPriority(4500);



	enemySpawnTime = (float)random(50, 150);
	enemySpawnTime /= 10.0f;

	enemySpawnTimeRemaining = enemySpawnTime;


	if (!font.loadFromFile("..\\fontti.TTF"))
	{
		throw "Unable to load font";
	}

	score = new Text();
	score->setFont(font);
	score->setCharacterSize(30);
	score->setColor(Color::White);
	score->setPosition(4, 4);

	honey = new Text();
	honey->setFont(font);
	honey->setCharacterSize(30);
	honey->setColor(Color::White);
	honey->setPosition(4, 38);

	gameOverScore = new Text();
	gameOverScore->setFont(font);
	gameOverScore->setCharacterSize(30);
	gameOverScore->setColor(Color::Green);
	gameOverScore->setPosition(800 * 0.5f, 600 * 0.4f);

	gameOverScore->setString("");

	setScore(0);
	setHoney(200);
}