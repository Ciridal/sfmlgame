#include "Enemy.h"


Enemy::Enemy()
{
	enemy = RectangleShape();
	enemy.setSize(Vector2f( 50,100));
	enemy.setFillColor(Color::Magenta);
	enemy.setPosition(700, 500);
}


Enemy::~Enemy()
{
}

void Enemy::Update(Clock& clock)
{

}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(enemy);
}