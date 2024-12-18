#pragma once
#include "../BaseSolver.h"

class Day08 : public BaseSolver
{
public:
	void ReadInput(bool bUseTestInput) override;
	string SolvePart1() override;
	string SolvePart2() override;

private:
	int Width = 0;
	int Height = 0;
	unordered_map<char, vector<pair<int, int>>> Antennas;

	bool IsInGrid(int x, int y) const
	{
		return x >= 0 && x < Width && y >= 0 && y < Height;
	}
};

