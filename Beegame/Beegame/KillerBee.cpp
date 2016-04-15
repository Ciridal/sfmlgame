#include "KillerBee.h"


KillerBee::KillerBee()
{
	killerB = CircleShape(50);
	
	

	killerB.setPosition(100, 500);

	isClicked = false;

	if (!killerTexture.loadFromFile("..\\killerbeetexture.png"))
	{

	}

	killerB.setTexture(&killerTexture);
	
}


KillerBee::~KillerBee()
{
}

void KillerBee::Update(Clock& clock)
{

}
void KillerBee::Draw(RenderWindow& window)
{
	if (Mouse::isButtonPressed(Mouse::Right))
	{
		isClicked = true;
	}

	if (isClicked)
	{
		
		window.draw(killerB);
	}
}