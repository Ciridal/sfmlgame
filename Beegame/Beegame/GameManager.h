#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Run();

	static Scene* activeScene;
	static Game* game;
	static sf::RenderWindow* window;

	static void ChangeScene(Scene* scene)
	{
		activeScene = scene;
	}
};

