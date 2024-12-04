#pragma once
#include "../BaseSolver.h"

class Day01 : public BaseSolver
{
public:
	int SolvePart1() override;
	int SolvePart2() override;

private:
	vector<int> leftColumn;
	vector<int> rightColumn;
};

