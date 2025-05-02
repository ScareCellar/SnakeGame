#pragma once
#include "raylib.h"
#include "raymath.h"

class Bomb
{
	Vector2 position;

public:
	

	void Draw(int cellSize)
	{
		DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, BLACK);
	}

	void Reposition(int cellCount, Vector2 foodPosition)
	{
		float xPos = GetRandomValue(1, cellCount - 2);
		float yPos = GetRandomValue(1, cellCount - 2);
		position = { xPos, yPos };
		
	if (position == foodPosition)
	{
		Reposition(cellCount,foodPosition);
	}
	}

	Vector2 GetBombPosition()
	{
		return position;
	}

		
};
