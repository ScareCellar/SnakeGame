#pragma once
#include "raylib.h"


class Food
{
	Vector2 position;
	
	

public:
	void Draw(int cellSize)
	{
		DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, RED);
	}

	void Reposition(int cellCount)
	{
		float xPos = GetRandomValue(1, cellCount - 2);
		float yPos = GetRandomValue(1, cellCount - 2);
		position = { xPos, yPos };
	}

	Vector2 GetFoodPosition() 
	{
		return position;
	}
};