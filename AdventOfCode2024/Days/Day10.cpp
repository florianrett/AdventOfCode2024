#include "Day10.h"

void Day10::ReadInput(bool bUseTestInput)
{
	BaseSolver::ReadInput(bUseTestInput);

	Height = Input.size();
	Width = Input[0].length();
	for (string line : Input)
	{
		vector<int> row;
		for (char c : line)
		{
			row.push_back(c - '0');
		}
		HeightMap.push_back(row);
	}
}

string Day10::SolvePart1()
{
	int scores = 0;
	for (int y = 0; y < Height; ++y)
	{
		for (int x = 0; x < Width; ++x)
		{
			if (HeightMap[y][x] == 0)
			{
				scores += CountPeaks(x, y).size();
			}
		}
	}
	return to_string(scores);
}

string Day10::SolvePart2()
{
	int ratings = 0;
	for (int y = 0; y < Height; ++y)
	{
		for (int x = 0; x < Width; ++x)
		{
			if (HeightMap[y][x] == 0)
			{
				ratings += CountPaths(x, y);
			}
		}
	}
	return to_string(ratings);
}

unordered_set<int> Day10::CountPeaks(int x, int y)
{
	const int height = HeightMap[y][x];
	if (height == 9)
		return unordered_set<int>({y*Width + x});

	unordered_set<int> peaks;
	if (IsValidIndex(x - 1, y) && HeightMap[y][x - 1] == height + 1)
		peaks.merge(CountPeaks(x - 1, y));
	if (IsValidIndex(x + 1, y) && HeightMap[y][x + 1] == height + 1)
		peaks.merge(CountPeaks(x + 1, y));
	if (IsValidIndex(x, y - 1) && HeightMap[y - 1][x] == height + 1)
		peaks.merge(CountPeaks(x, y - 1));
	if(IsValidIndex(x, y + 1) && HeightMap[y + 1][x] == height + 1)
		peaks.merge(CountPeaks(x, y + 1));

	// cout << x << " " << y << " " << height << " " << peaks.size() << endl;
	return peaks;
}

int Day10::CountPaths(int x, int y)
{
	const int height = HeightMap[y][x];
	if (height == 9)
		return 1;

	int paths = 0;
	if (IsValidIndex(x - 1, y) && HeightMap[y][x - 1] == height + 1)
		paths += CountPaths(x - 1, y);
	if (IsValidIndex(x + 1, y) && HeightMap[y][x + 1] == height + 1)
		paths += CountPaths(x + 1, y);
	if (IsValidIndex(x, y - 1) && HeightMap[y - 1][x] == height + 1)
		paths += CountPaths(x, y - 1);
	if(IsValidIndex(x, y + 1) && HeightMap[y + 1][x] == height + 1)
		paths += CountPaths(x, y + 1);

	// cout << x << " " << y << " " << height << " " << peaks.size() << endl;
	return paths;
}
