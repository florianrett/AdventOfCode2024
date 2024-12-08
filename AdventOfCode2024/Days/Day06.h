#pragma once
#include "../BaseSolver.h"

class Day06 : public BaseSolver
{
public:
	void ReadInput(bool bUseTestInput) override;
	int SolvePart1() override;
	int SolvePart2() override;

private:
	int Width = 0;
	int Height = 0;
	unordered_set<int> Obstacles;
	int GuardX = 0;
	int GuardY = 0;
	unordered_set<int> Path;

	int Get2dIdx(int x, int y)
	{
		return x * Width + y;
	}
};

