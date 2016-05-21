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
	static RenderWindow* window;

	Clock clock;

	Game();
	~Game();

	void Update();
	void Draw();
	template <typename T>
	T* Instantiate(std::string texturePath) 
	{
		T* gameObject = new T(texturePath);
		gameObjects.push_back(gameObject);
		return gameObject;
	}

private:
	std::vector<GameObject*> gameObjects;

	int pointAmount = 0;
	int honeyAmount = 0;

};

