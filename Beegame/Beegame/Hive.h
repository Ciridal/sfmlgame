#pragma once
class Hive
{
public:
	Hive(int health, int score);
	~Hive();

	int damage();

private:
	int hp=50;
};

