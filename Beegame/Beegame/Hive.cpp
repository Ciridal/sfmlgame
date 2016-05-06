#include "Hive.h"


Hive::Hive()
{
	hive = CircleShape(80);
	
	hive.setPosition(10, 400);



	if (!hiveTexture.loadFromFile("..\\beehivetexture.png"))
	{

	}

	hive.setTexture(&hiveTexture);
	
	if (!font.loadFromFile("..\\fontti.TTF"))
	{
		
	}

	points.setFont(font);
	points.setString("Points: ");
	points.setCharacterSize(24);
	points.setColor(Color::White);

	honey.setFont(font);
	honey.setString("Honey: ");
	honey.setCharacterSize(24);
	honey.setColor(Color::White);
	honey.setPosition(0, 24);
}


Hive::~Hive()
{
}


void Hive::Draw(RenderWindow& window)
{
	window.draw(hive);
	window.draw(points);
	window.draw(honey);
}

void Hive::Update(Clock& clock)
{

}

void Hive::takeDamage()
{
	if (isHit == true)
	{
		health-5;
	}

}