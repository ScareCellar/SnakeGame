#pragma once
#include <deque>
#include "raylib.h"
#include "raymath.h"
#include <chrono>
#include <thread>
#include <string>

class Snake
{
	std::deque<Vector2> body = {Vector2{5,9}, Vector2{4,9}, Vector2{3,9} };
	Vector2 direction = { 0,0 };

	double lastUpdateTime = 0;

public:
	
	void Draw(int cellSize);

	void MoveSnake(Vector2 direction, bool doGrow);

	Vector2 GetSnakeHead();

	bool CheckForDead(int cellSize);

	void Die(int cellSize, std::string gameOver);
	
};
