#include "Day04.h"

void Day04::ReadInput(bool bUseTestInput)
{
	BaseSolver::ReadInput(bUseTestInput);

	numRows = Input.size();
	numColumns = Input[0].length();
}

int Day04::SolvePart1()
{
	int numXmas = 0;
	for (int y = 0; y < numRows; ++y)
	{
		for (int x = 0; x < numColumns; ++x)
		{
			if (TestXmas(x, y, 0, 1))
			{
				++numXmas;
			}
			if (TestXmas(x, y, 1, 1))
			{
				++numXmas;
			}
			if (TestXmas(x, y, 1, 0))
			{
				++numXmas;
			}
			if (TestXmas(x, y, 1, -1))
			{
				++numXmas;
			}
			if (TestXmas(x, y, 0, -1))
			{
				++numXmas;
			}
			if (TestXmas(x, y, -1, -1))
			{
				++numXmas;
			}
			if (TestXmas(x, y, -1, 0))
			{
				++numXmas;
			}
			if (TestXmas(x, y, -1, 1))
			{
				++numXmas;
			}
		}
	}
	return numXmas;
}

int Day04::SolvePart2()
{
	int numXmas = 0;
	for (int y = 0; y < numRows; ++y)
	{
		for (int x = 0; x < numColumns; ++x)
		{
			if (TestCrossMas(x, y))
			{
				++numXmas;
			}
		}
	}
	return numXmas;
}

bool Day04::IsValidIndex(int row, int column)
{
	return row >= 0 && row < numRows && column >= 0 && column < numColumns;
}

bool Day04::TestXmas(int x, int y, int offX, int offY)
{
	string xmas = "XMAS";
	for (int i = 0; i < 4; ++i)
	{
		if (!IsValidIndex(x + offX * i, y + offY * i))
			return false;
		if (Input[y + offY * i][x + offX * i] != xmas[i])
		{
			return false;
		}
	}
	return true;
}

bool Day04::TestCrossMas(int x, int y)
{
	if (!IsValidIndex(x - 1, y - 1) || !IsValidIndex(x + 1, y + 1))
		return false;
	if (Input[y][x] == 'A')
	{
		if  (((Input[y+1][x+1] == 'M' && Input[y-1][x-1] == 'S') || (Input[y+1][x+1] == 'S' && Input[y-1][x-1] == 'M'))
			&& ((Input[y-1][x+1] == 'M' && Input[y+1][x-1] == 'S') || (Input[y-1][x+1] == 'S' && Input[y+1][x-1] == 'M')))
		{
			return true;
		}
	}
	return false;
}
