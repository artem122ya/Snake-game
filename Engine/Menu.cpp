#include "Menu.h"
#include "SpriteCodex.h"
#include <string>


void Menu::DrawMenu(Graphics & gfx)
{
	SpriteCodex::DrawTitle(titleX, titleY, gfx);
	this->DrawStartButton(gfx);
	this->DrawDifficulty(gfx);
}

void Menu::DrawDifficulty(Graphics & gfx)
{
	SpriteCodex::DrawDifficultyTitle(difficultyX - 75, difficultyY - 55, gfx);
	if (selectedOption == DIFFICULTY)
	{
		if (currentDifficulty == 1)
		{
			SpriteCodex::DrawDifficulty1selected(difficultyX, difficultyY, gfx);
		}
		else if (currentDifficulty == 2)
		{
			SpriteCodex::DrawDifficulty2selected(difficultyX, difficultyY, gfx);
		}
		else if (currentDifficulty == 3)
		{
			SpriteCodex::DrawDifficulty3selected(difficultyX, difficultyY, gfx);
		}
	}
	else
	{
		if (currentDifficulty == 1)
		{
			SpriteCodex::DrawDifficulty1(difficultyX, difficultyY, gfx);
		}
		else if (currentDifficulty == 2)
		{
			SpriteCodex::DrawDifficulty2(difficultyX, difficultyY, gfx);
		}
		else if (currentDifficulty == 3)
		{
			SpriteCodex::DrawDifficulty3(difficultyX, difficultyY, gfx);
		}
	}
}

void Menu::DrawStartButton(Graphics & gfx)
{
	if (selectedOption == START)
	{
		SpriteCodex::DrawStartGameButtonSelected(startButtonX, startButtonY, gfx);
	} 
	else
	{
		SpriteCodex::DrawStartGameButton(startButtonX, startButtonY, gfx);
	}
}

void Menu::UpdateMenu()
{
}

void Menu::UpKeyPressed(Graphics & gfx)
{
	if (selectedOption == START)
	{
		selectedOption = DIFFICULTY;
	}
	else if (selectedOption == DIFFICULTY)
	{
		selectedOption = START;
	}
}

void Menu::DownKeyPressed(Graphics & gfx)
{
	if (selectedOption == START)
	{
		selectedOption = DIFFICULTY;
	}
	else if (selectedOption == DIFFICULTY)
	{
		selectedOption = START;
	}
}

void Menu::RightKeyPressed(Graphics & gfx)
{
}

void Menu::LeftKeyPressed(Graphics & gfx)
{
}

void Menu::EnterKeyPressed(Graphics & gfx)
{
	if (selectedOption == START)
	{
		gameIsStarted = true;
	} 
	else if (selectedOption == DIFFICULTY)
	{
		if (currentDifficulty == 1)
		{
			currentDifficulty = 2;
		}
		else if (currentDifficulty == 2)
		{
			currentDifficulty = 3;
		}
		else if (currentDifficulty == 3)
		{
			currentDifficulty = 1;
		}
		this->DrawDifficulty(gfx);
	}
}

bool Menu::getgameStarted()
{
	return gameIsStarted;
}

void Menu::setgameStarted(bool x)
{
	gameIsStarted = x;
}

int* Menu::GetCurrentDifficulty()
{
	return &currentDifficulty;
}
