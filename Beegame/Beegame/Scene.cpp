#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
	cleanUp();
}

void Scene::updateGameObjectList()
{
	while (destroyObjects.size() > 0)
	{
		std::vector<GameObject*>::iterator iter = std::find(gameObjects.begin(), gameObjects.end(), destroyObjects.at(0));
		if (iter != gameObjects.end())
		{
			delete *iter;
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

	if (requiresSort)
		std::sort(gameObjects.begin(), gameObjects.end(), GameObject::compareRenderPriority);
}

void Scene::cleanUp()
{
	for (GameObject* gameObject : gameObjects)
	{
		destroy(gameObject);
	}

	updateGameObjectList();
	gameObjects.empty();
}

void Scene::destroy(GameObject* gameObject)
{
	destroyObjects.push_back(gameObject);
}

void Scene::Update(float dt)
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Update(dt);
	}

	updateGameObjectList();
}

void Scene::Draw(sf::RenderWindow& window)
{
	window.clear(sf::Color(135, 206, 255));

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw(window);
	}
	window.display();
}