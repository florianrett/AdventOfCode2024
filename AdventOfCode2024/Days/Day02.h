#pragma once
#include "../BaseSolver.h"

class Day02 : public BaseSolver
{
public:
	int SolvePart1() override;
	int SolvePart2() override;

private:
	vector<int> GenerateDeltas(vector<int> report);
	bool TestSafety(vector<int> const& deltas);
	
	vector<vector<int>> Data;
};

