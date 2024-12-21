#pragma once
#include "../BaseSolver.h"

class Day10 : public BaseSolver
{
public:
	void ReadInput(bool bUseTestInput) override;
	string SolvePart1() override;
	string SolvePart2() override;

private:
	vector<vector<int>> HeightMap;
	int Width = 0;
	int Height = 0;

	bool IsValidIndex(int x, int y) const
	{
		return x >= 0 && x < Width && y >= 0 && y < Height;
	}

	unordered_set<int> CountPeaks(int x, int y);
	int CountPaths(int x, int y);
};

