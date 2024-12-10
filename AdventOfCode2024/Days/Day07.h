#pragma once
#include "../BaseSolver.h"

class Day07 : public BaseSolver
{
public:
	void ReadInput(bool bUseTestInput) override;
	string SolvePart1() override;
	string SolvePart2() override;

private:
	vector<vector<long long>> Equations;
};

