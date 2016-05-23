#pragma once
#include <SFML/Graphics.hpp>
#include "Vektori2.h"
#include "GameObject.h"

using namespace sf;

class Hive : public GameObject
{
public:
	


	Hive(std::string texturePath);
	~Hive();

	
	void Update(float dt) override;


private:
	
	

};

