#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Hive
{
public:


	Font font;
	Text points;
	Text honey;

	CircleShape hive;
	
	Hive();
	~Hive();

	static Vector2i getPosition(const Window &relativeTo);

	
	void Update(Clock& clock);
	void Draw(RenderWindow& window);;

private:
	
	int pointAmount = 0;
	int honeyAmount = 0;
};

