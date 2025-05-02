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
	
	void Draw(int cellSize)
	{
		if (!body.empty())
		{
			for (size_t i = 0; i < body.size(); i++)
			{
				Vector2 segment = body[i];
				DrawRectangle((int)(segment.x * cellSize),(int)(segment.y * cellSize), cellSize, cellSize, DARKGREEN);
			}
		}
	}

	void MoveSnake(Vector2 direction, bool doGrow)
	{
		//direction = { 0,1 };

		Vector2 newPosition = { body[0].x + direction.x, body[0].y + direction.y };
		body.push_front(Vector2Add(body[0], direction));
		if (!doGrow)
		{
			body.pop_back();
		}
	}

	Vector2 GetSnakeHead()
	{
		if (!body.empty())
		{
			return body[0];
		}
		return { 0,0 };
	}

	bool CheckForDead(int cellSize)
	{
		for (int i = 1; i < body.size(); i++)
		{
			if (GetSnakeHead() == body[i])
			{
				return true;
			}
		}
		
		if (GetSnakeHead().x*30 < cellSize || GetSnakeHead().y*30 < cellSize || GetSnakeHead().x*30 >= GetScreenWidth() - cellSize || GetSnakeHead().y*30 >= GetScreenHeight() - cellSize)
		{
			return true;
		}
		return false;
	}

	void Die(int cellSize, std::string gameOver)
	{
		if (!body.empty())
		{
			body.pop_front();

			DrawText(gameOver.c_str(), (GetScreenWidth() / 2) - 80, (GetScreenHeight() / 2) - 80, 40, WHITE);

			WaitTime(0.2);
		}
	}
};

//  || GetSnakeHead().y < cellSize || GetSnakeHead().x >= GetScreenWidth() - cellSize || GetSnakeHead().y >= GetScreenHeight() - cellSize
