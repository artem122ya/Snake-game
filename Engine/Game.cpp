/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
#include "Menu.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng( std::random_device()() ),
	snake({2,2}),
	goal(rng, brd, snake)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (menu.getgameStarted())
	{
		if (!gameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				if (!(delta_loc == delta_down) || snake.GetnSegments() == 1)
					delta_next = delta_up;
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				if (!(delta_loc == delta_up) || snake.GetnSegments() == 1)
					delta_next = delta_down;
			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				if (!(delta_loc == delta_right) || snake.GetnSegments() == 1)
					delta_next = delta_left;
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				if (!(delta_loc == delta_left) || snake.GetnSegments() == 1)
					delta_next = delta_right;
			}

			++snakeMoveCounter;
			if (snakeMoveCounter >= snakeMovePeriod)
			{
				delta_loc = delta_next;
				snakeMoveCounter = 0;
				const Location next = snake.GetNextHeadLocation(delta_loc);
				if (!brd.IsInsideBoard(next) || snake.IsInTile(next))
				{
					gameIsOver = true;
				}
				else
				{
					bool eating = next == goal.GetLocation();
					if (eating)
					{
						snake.Grow();
					}
					snake.MoveBy(delta_loc);
					if (eating)
					{
						goal.Respawn(rng, brd, snake);
						if (difficultyLvl == 1) 
						{
							score.addPoints(1);
						}
						else if (difficultyLvl == 2)
						{
							score.addPoints(1.5);
						}
						else if (difficultyLvl == 3)
						{
							score.addPoints(2);
						}
					}
				}
			}
		}
		score.ClearScoreBoard(gfx);
		score.UpdateScoreBoard(gfx);
	}
	else 
	{
		++menuCounter;
		// Menu
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			if (menuCounter >= menuCounterPeriod)
			{
				menu.UpKeyPressed(gfx);
				menuCounter = 0;
			}
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			if (menuCounter >= menuCounterPeriod)
			{
				menu.DownKeyPressed(gfx);
				menuCounter = 0;
			}
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			if (menuCounter >= menuCounterPeriod)
			{
				menu.LeftKeyPressed(gfx);
				menuCounter = 0;
			}
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{ 
			if (menuCounter >= menuCounterPeriod)
			{
				menu.RightKeyPressed(gfx);
				menuCounter = 0;
			}
		}
		else if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			if (menuCounter >= menuCounterPeriod)
			{
				menu.EnterKeyPressed(gfx);
				menuCounter = 0;
			}
		}
		// End of menu
	}
}


void Game::ComposeFrame()
{
	if (menu.getgameStarted())
	{
		difficultyLvl = *(menu.GetCurrentDifficulty());
		snake.Draw(brd);
		goal.Draw(brd);
		if (gameIsOver)
		{
			SpriteCodex::DrawGameOver(90, 265, gfx);
			if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
				gameIsOver = false;
				delta_loc = { 1, 0 };
				delta_next = { 1, 0 };
				snake.SetnSegments(1);
				snake.SnakeInitHead({ 2,2 });
				score.ResetScore();
				goal.Respawn(rng, brd, snake);
				menu.setgameStarted(false);
			}
		}
		brd.DrawBorder();
		if (difficultyLvl == 1)
		{
			snakeMovePeriod = 14;
		}
		else if (difficultyLvl == 2)
		{
			snakeMovePeriod = 9;
		}
		else if (difficultyLvl == 3)
		{
			snakeMovePeriod = 5;
		}
	}
	else
	{
		menu.DrawMenu(gfx);
	}
}
