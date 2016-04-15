#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class KillerBee
{
public:

	CircleShape killerB;
	Texture killerTexture;

	KillerBee();
	~KillerBee();

	void Update(Clock& clock);
	void Draw(RenderWindow& window);

private:
	bool isClicked;
};

