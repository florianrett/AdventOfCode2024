#include "Day08.h"

#include <numeric>

void Day08::ReadInput(bool bUseTestInput)
{
	BaseSolver::ReadInput(bUseTestInput);

	Height = Input.size();
	Width = Input[0].length();

	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			char frequency = Input[y][x];
			if (frequency == '.')
				continue;

			if (!Antennas.contains(frequency))
				Antennas[frequency] = vector<pair<int, int>>();

			Antennas[frequency].emplace_back(x, y);
		}
	}
}

string Day08::SolvePart1()
{
	unordered_set<int> antinodes;

	for (auto freq : Antennas)
	{
		const vector<pair<int, int>>& antennas = freq.second;

		for (auto a = antennas.begin(); a != antennas.end(); ++a)
		{
			for (auto b = a + 1; b != antennas.end(); ++b)
			{
				int x1 = a->first;
				int y1 = a->second;
				int deltaX = b->first - x1;
				int deltaY = b->second - y1;

				int candidateX = x1 - deltaX;
				int candidateY = y1 - deltaY;
				if (IsInGrid(candidateX, candidateY))
				{
					antinodes.insert(candidateY * Width + candidateX);
					// cout << freq.first << " " << candidateX << " " << candidateY << endl;
				}
				
				candidateX = x1 + 2 * deltaX;
				candidateY = y1 + 2 * deltaY;
				if (IsInGrid(candidateX, candidateY))
				{
					antinodes.insert(candidateY * Width + candidateX);
					// cout << freq.first << " " << candidateX << " " << candidateY << endl;
				}
			}
		}
	}
	
	return to_string(antinodes.size());
}

string Day08::SolvePart2()
{
	unordered_set<int> antinodes;

	for (auto freq : Antennas)
	{
		const vector<pair<int, int>>& antennas = freq.second;

		for (auto a = antennas.begin(); a != antennas.end(); ++a)
		{
			for (auto b = a + 1; b != antennas.end(); ++b)
			{
				int x1 = a->first;
				int y1 = a->second;
				int deltaX = b->first - x1;
				int deltaY = b->second - y1;
			
				// divide deltas by greatest common denominator
				int div = gcd(deltaX, deltaY);
				deltaX /= div;
				deltaY /= div;

				int candidateX = x1;
				int candidateY = y1;

				while (IsInGrid(candidateX, candidateY))
				{
					antinodes.insert(candidateY * Width + candidateX);
					candidateX -= deltaX;
					candidateY -= deltaY;
				}
				candidateX = x1 + deltaX;
				candidateY = y1 + deltaY;
				while (IsInGrid(candidateX, candidateY))
				{
					antinodes.insert(candidateY * Width + candidateX);
					candidateX += deltaX;
					candidateY += deltaY;
				}

			}
		}
	}
	
	return to_string(antinodes.size());
}
