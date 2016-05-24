#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Scene
{
public:

	Scene();
	~Scene();

	template <typename T>
	T* Instantiate(std::string texturePath)
	{
		T* gameObject = new T(texturePath);
		newGameObjects.push_back(gameObject);
		return gameObject;
	}

	void destroy(GameObject* gameObject);

	void updateGameObjectList();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
	virtual void cleanUp();

protected:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> newGameObjects;
	std::vector<GameObject*> destroyObjects;
};

