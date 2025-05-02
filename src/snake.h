#pragma once
#include <deque>
#include "raylib.h"
#include "raymath.h"

class Snake
{
	std::deque<Vector2> body = {Vector2{5,9}, Vector2{4,9}, Vector2{3,9} };
	Vector2 direction = { 0,0 };

public:
	
	void Draw(int cellSize)
	{
		for (unsigned int i = 0; i < body.size(); i++)
		{
			int x = body[i].x;
			int y = body[i].y;
			DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, DARKGREEN);
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
		return body[0];
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
};

//  || GetSnakeHead().y < cellSize || GetSnakeHead().x >= GetScreenWidth() - cellSize || GetSnakeHead().y >= GetScreenHeight() - cellSize
