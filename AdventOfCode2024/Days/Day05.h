#pragma once
#include "../BaseSolver.h"

class Day05 : public BaseSolver
{
public:
	void ReadInput(bool bUseTestInput) override;
	string SolvePart1() override;
	string SolvePart2() override;

private:
	unordered_map<int, unordered_set<int>> PageOrders;
	vector<vector<int>> Updates;
	vector<vector<int>> IncorrectUpdates;
};

