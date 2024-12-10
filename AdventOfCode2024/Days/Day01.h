#pragma once
#include "../BaseSolver.h"

class Day01 : public BaseSolver
{
public:
	string SolvePart1() override;
	string SolvePart2() override;

private:
	vector<int> leftColumn;
	vector<int> rightColumn;
};

