#pragma once


#include "Graphics.h"
#include <string>

class Menu 
{
private:
	//std::string selectedOption = "start"; // start  difficulty
	enum MenuOptions {START, DIFFICULTY};
	MenuOptions selectedOption = START;
	int currentDifficulty = 1;
	bool gameIsStarted = false;
	static const int startButtonX = 304;
	static const int startButtonY = 250;
	static const int titleX = 205;
	static const int titleY = 0;
	static const int difficultyX = 365;
	static const int difficultyY = 400;
public:
	void DrawMenu(Graphics & gfx);
	void DrawDifficulty(Graphics & gfx);
	void DrawStartButton(Graphics & gfx);
	void UpdateMenu();
	void UpKeyPressed(Graphics & gfx);
	void DownKeyPressed(Graphics & gfx);
	void RightKeyPressed(Graphics & gfx);
	void LeftKeyPressed(Graphics & gfx);
	void EnterKeyPressed(Graphics & gfx);
	bool getgameStarted();
	void setgameStarted(bool);
	int* GetCurrentDifficulty();
};