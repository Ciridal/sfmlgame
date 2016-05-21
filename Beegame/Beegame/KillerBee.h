#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class KillerBee : public GameObject
{
public:

	CircleShape killerB;
	Texture killerTexture;

	KillerBee(std::string texturePath);
	~KillerBee();

	void Update(float dt) override;
	

private:
	bool isClicked;
};

