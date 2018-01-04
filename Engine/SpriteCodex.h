#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawGameOver( int x,int y,Graphics& gfx );
	static void DrawTitle( int x,int y,Graphics& gfx );
	static void Draw0(int x, int y, Graphics& gfx);
	static void Draw1(int x, int y, Graphics& gfx);
	static void Draw2(int x, int y, Graphics& gfx);
	static void Draw3(int x, int y, Graphics& gfx);
	static void Draw4(int x, int y, Graphics& gfx);
	static void Draw5(int x, int y, Graphics& gfx);
	static void Draw6(int x, int y, Graphics& gfx);
	static void Draw7(int x, int y, Graphics& gfx);
	static void Draw8(int x, int y, Graphics& gfx);
	static void Draw9(int x, int y, Graphics& gfx);
	static void DrawDifficulty1(int x, int y, Graphics& gfx);
	static void DrawDifficulty2(int x, int y, Graphics& gfx);
	static void DrawDifficulty3(int x, int y, Graphics& gfx);
	static void DrawDifficulty1selected(int x, int y, Graphics& gfx);
	static void DrawDifficulty2selected(int x, int y, Graphics& gfx);
	static void DrawDifficulty3selected(int x, int y, Graphics& gfx);
	static void DrawStartGameButton(int x, int y, Graphics& gfx);
	static void DrawStartGameButtonSelected(int x, int y, Graphics& gfx);
	static void DrawDifficultyTitle(int x, int y, Graphics& gfx);
};