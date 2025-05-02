#pragma once
#include <iostream>
#include "raylib.h"
#include <string>
#include <list>

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "food.h"
#include "snake.h"
#include "bomb.h"
int cellSize = 30;
int cellCount = 30;

bool doGrow = false;

double lastUpdateTime = 0;

std::list<Bomb>bombList;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

void CreateBombs(int score, Vector2 foodPosition)
{
	if (score / 25 != bombList.size())
	{
		for (int i = bombList.size(); i < (score / 25) + 1; i++)
		{
			bombList.push_back(Bomb());

		}
	}
}

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Food food = Food();
	Snake snake = Snake();
	Vector2 direction = { 1,0 };
	
	int score = 0;
	food.Reposition(cellCount);
	
	SetTargetFPS(30);
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		while (!snake.CheckForDead(cellSize))
		{
			BeginDrawing();
			ClearBackground(BLACK);
			std::string scoreS = std::to_string(score);
			DrawText(scoreS.c_str(), 0, 0, 30, WHITE);
			DrawRectangle(cellSize, cellSize, cellSize * (cellCount - 2), cellSize * (cellCount - 2), GREEN);
			
			food.Draw(cellSize);
			snake.Draw(cellSize);
			for (Bomb bomb : bombList)
			{
				bomb.Draw(cellSize);
			}
			if (EventTriggered(0.2))
			{
				if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
				{
					if (direction != Vector2{ 0,1 })
					{
						direction = { 0,-1 };
					}
				}
				else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
				{
					if (direction != Vector2{ 1,0 })
					{
						direction = { -1,0 };
					}
				}
				else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
				{
					if (direction != Vector2{ 0,-1 })
					{
						direction = { 0,1 };
					}
				}
				else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
				{
					if (direction != Vector2{ -1,0 })
					{
						direction = { 1,0 };
					}
				}

				snake.MoveSnake(direction, doGrow);
				doGrow = false;
			}

			if (food.GetFoodPosition() == snake.GetSnakeHead())
			{
				food.Reposition(cellCount);
				score++;

				doGrow = true;

				for (Bomb bomb : bombList)
				{
					bomb.Reposition(cellCount, food.GetFoodPosition());
				}
			}

			EndDrawing();
		}
		BeginDrawing();
		std::string gameOver ="Game Over!\nScore: " + std::to_string(score);
		DrawText(gameOver.c_str(), (GetScreenWidth() / 2) - 80, (GetScreenHeight() / 2) - 80,40, WHITE);
		EndDrawing();
	}

	
	

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}


