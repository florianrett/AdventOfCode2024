#pragma once
#include "../BaseSolver.h"

class Day04 : public BaseSolver
{
public:
	void ReadInput(bool bUseTestInput) override;
	string SolvePart1() override;
	string SolvePart2() override;

private:
	bool IsValidIndex(int row, int column);
	bool TestXmas(int x, int y, int offX, int offY);
	bool TestCrossMas(int x, int y);

	int numRows = 0;
	int numColumns = 0;
};

