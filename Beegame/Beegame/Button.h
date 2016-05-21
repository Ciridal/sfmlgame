#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Game;

class Button : public GameObject
{
public:
	typedef void (Game::*ClickAction)();

	enum State
	{
		Up,
		Down
	};

	State state;
	
	void Update(float dt) override;

	Button(std::string texturePath);
	~Button();

	ClickAction onClicked;
};

