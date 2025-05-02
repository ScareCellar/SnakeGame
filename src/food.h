#pragma once
#include "raylib.h"


class Food
{
	Vector2 position;
	
	

public:
	void Draw(int cellSize);

	void Reposition(int cellCount);

	Vector2 GetFoodPosition();
};