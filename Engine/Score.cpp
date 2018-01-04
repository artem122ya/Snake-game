#include "Score.h"
#include "SpriteCodex.h"
#include "Graphics.h"
#include <string>



Score::Score()
{
	score = 0;
}

void Score::addPoints(float x)
{
	score += x;
}

void Score::UpdateScoreBoard(Graphics & gfx)
{
	int intscore = (int)score;
	int currNum;
	std::string currScore = std::to_string(intscore);
	for (int i = 0; i < currScore.length(); i++)
	{

		// Draw scoreboard
		if (currScore.length() < maxDigits)
		{
			currNum = currScore.at(i) - 48;
			if (currNum == 1) {
				SpriteCodex::Draw1(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 2) {
				SpriteCodex::Draw2(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 3) {
				SpriteCodex::Draw3(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 4) {
				SpriteCodex::Draw4(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 5) {
				SpriteCodex::Draw5(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 6) {
				SpriteCodex::Draw6(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 7) {
				SpriteCodex::Draw7(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 8) {
				SpriteCodex::Draw8(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 9) {
				SpriteCodex::Draw9(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
			if (currNum == 0) {
				SpriteCodex::Draw0(scoreBoardX + (maxDigits - (currScore.length() - 1) + i) * 22, scoreBoardY, gfx);
			}
		}
	}
}



void Score::ClearScoreBoard(Graphics & gfx)
{
	for (int i = 1; i <= maxDigits; i++)
	{
		for (int k = 0; k < 35; k++)
		{
			for (int j = 0; j < 20; j++) {
				gfx.PutPixel(scoreBoardX + i * 22 + j, scoreBoardY + k, 0, 0, 0);
			}
		}
	}
}

void Score::ResetScore()
{
	score = 0;
}
