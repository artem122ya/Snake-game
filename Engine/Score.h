#pragma once
#include "Graphics.h"

class Score
{
private:
	float score;
	static constexpr int scoreBoardX = 350;
	static constexpr int scoreBoardY = 2;
	static constexpr int maxDigits = 10;
public:
	Score();
	void addPoints(float x);
	void UpdateScoreBoard(Graphics & gfx);
	void ClearScoreBoard(Graphics & gfx);
	void ResetScore();
};