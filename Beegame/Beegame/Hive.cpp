#include "Hive.h"


Hive::Hive(std::string texturePath) 
	: GameObject(texturePath)
{
	hive.setPosition(10, 400);
	
	/*

	*/
}


Hive::~Hive()
{
}

/*
void Hive::Draw(RenderWindow& window)
{
	window.draw(hive);
	window.draw(points);
	window.draw(honey);
}
*/

void Hive::Update(float dt)
{

}

void Hive::takeDamage()
{
	if (isHit == true)
	{
		health-5;
	}

}