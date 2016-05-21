#include "Enemy.h"


Enemy::Enemy(std::string texturePath) 
	: GameObject (texturePath)
{
	

	//sprite.setSize(Vector2f( 50,100));
	//enemy.setFillColor(Color::Magenta);
	//enemy.setPosition(700, 500);
}


Enemy::~Enemy()
{
}

void Enemy::Update(float dt)
{

}

