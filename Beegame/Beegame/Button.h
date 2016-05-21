#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Button : public GameObject
{
public:

	enum State
	{
		Up,
		Down
	};

	State state;
	
	void Update(float dt) override;

	Button(std::string texturePath);
	~Button();
};

