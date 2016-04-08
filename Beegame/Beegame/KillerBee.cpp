#include "KillerBee.h"


KillerBee::KillerBee()
{
	killerB = CircleShape(4);
	killerB.setFillColor(Color::Red);
	killerB.setPosition(100, 500);
	isClicked = false;
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