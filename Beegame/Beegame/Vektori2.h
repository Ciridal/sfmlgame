#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Vektori2
{
public:

	Vektori2()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	Vektori2(sf::Vector2f vec)
	{
		X = vec.x;
		Y = vec.y;
	}

	Vektori2(float x, float y)
	{
		X = x;
		Y = y;
	};

	Vektori2& operator+=(const Vektori2& rhs)
	{
		X = X + rhs.X;

		Y = Y + rhs.Y;

		return *this;
	}

	Vektori2& operator*(float value)
	{
	
		X = X * value;

		Y = Y * value;

		return *this;
	}

	Vektori2& operator*=(float value)
	{

		X = X * value;

		Y = Y * value;

		return *this;
	}

	Vektori2& operator/=(float value)
	{

		X = X / value;

		Y = Y / value;

		return *this;
	}

	float Magnitude()
	{
		return std::sqrt((X * X) + (Y * Y));
	}

	void Normalize()
	{
		float length = Magnitude();

		X = X / length;
		Y = Y / length;
	}

	
	~Vektori2(){};

	float X;
	float Y;
};
