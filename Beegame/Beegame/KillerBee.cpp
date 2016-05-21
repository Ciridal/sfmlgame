#include "KillerBee.h"


KillerBee::KillerBee(std::string texturePath) 
	: GameObject(texturePath)
{
	
	killerB.setPosition(100, 500);

	isClicked = false;
}


KillerBee::~KillerBee()
{
}

void KillerBee::Update(float dt)
{

}
