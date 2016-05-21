#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "WorkerBee.h"
#include "Hive.h"
#include "Enemy.h"
#include "KillerBee.h"
#include "Button.h"

using namespace sf;

class Game
{
public:
	static Game* instance;

	RenderWindow* window;

	Event event;

	Clock clock;

	Game();
	~Game();

	void Update();
	void Draw();
	template <typename T>
	T* Instantiate(std::string texturePath) 
	{
		T* gameObject = new T(texturePath);
		newGameObjects.push_back(gameObject);
		return gameObject;
	}

	void destroy(GameObject* gameObject);

	void updateGameObjectList();

	void setHoney(int honeyAmount);
	void setScore(int scoreAmount);

	void addHoney(int honeyAmount);

	void spawnWorkerBee();
	void spawnKillerBee();

private:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> newGameObjects;
	std::vector<GameObject*> destroyObjects;

	int scoreAmount;
	int honeyAmount;

	Font font;
	Text score;
	Text honey;

};

