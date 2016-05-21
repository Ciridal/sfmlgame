#pragma once
#include <SFML/Graphics.hpp>
#include "Vektori2.h"
#include "GameObject.h"

using namespace sf;

class Hive : public GameObject
{
public:
	

	Font font;
	Text points;
	Text honey;

	CircleShape hive;
	Texture hiveTexture;

	Hive(std::string texturePath);
	~Hive();

	Vektori2 getPosition(const Window &relativeTo) {};

	
	void Update(float dt) override;
	//void Draw(RenderWindow& window) override;
	void takeDamage();
	

private:
	
	bool isHit;


	int health = 50;
};

