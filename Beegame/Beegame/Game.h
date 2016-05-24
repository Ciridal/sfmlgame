#pragma once

#include "WorkerBee.h"
#include "Hive.h"
#include "Enemy.h"
#include "KillerBee.h"
#include "Button.h"
#include "Scene.h"

using namespace sf;

class Game : public Scene
{
public:
	static Game* instance;

	Game();
	~Game();

	Event event;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void setHoney(int honeyAmount);
	void setScore(int scoreAmount);

	void addHoney(int honeyAmount);
	void reduceHoney(int amount);
	void addScore(int scoreAmount);

	void spawnWorkerBee();
	void spawnKillerBee();

	void spawnEnemy();

	int random(int minValue, int maxValue);
	float random(float minValue, float maxValue);

	void gameOver();

	void restart();
	void restartClicked();

	void cleanUp() override;

private:
	Text* gameOverScore;

	int scoreAmount;
	int honeyAmount;
	bool pendingRestart;

	Font font;
	Text* score;
	Text* honey;

	float enemySpawnTimeRemaining;
	float enemySpawnTime;
};

