#pragma once
#include "../BaseSolver.h"

class Day02 : public BaseSolver
{
public:
	string SolvePart1() override;
	string SolvePart2() override;

private:
	vector<int> GenerateDeltas(vector<int> report);
	bool TestSafety(vector<int> const& deltas);
	
	vector<vector<int>> Data;
};

