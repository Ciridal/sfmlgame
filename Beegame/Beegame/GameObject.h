#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void update(float deltatime);
};

