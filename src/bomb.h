#pragma once
#include "raylib.h"
#include "raymath.h"

class Bomb
{
	Vector2 position;

public:
	

	void Draw(int cellSize);
	
	void Reposition(int cellCount, Vector2 foodPosition);

	Vector2 GetBombPosition();

};
