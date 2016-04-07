#include "KillerBee.h"


KillerBee::KillerBee()
{
	killerB = CircleShape(4);
	killerB.setFillColor(Color::Red);
	killerB.setPosition(100, 500);
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
		window.draw(killerB);
	}
}