#include "Day11.h"
#include "../RegexHelper.h"

void Day11::ReadInput(bool bUseTestInput)
{
	BaseSolver::ReadInput(bUseTestInput);

	for( string s : RegexHelper::FindAllMatches("[0-9]+", Input[0]))
	{
		InitialStones.push_back(stoi(s));
	}
}

string Day11::SolvePart1()
{
	// list<int> stones(InitialStones.begin(), InitialStones.end());

	uint64_t numStones = 0;
	for  (int s : InitialStones)
	{
		numStones += CountStonesRec(s, 25);
	}
	
	return to_string(numStones);
}

string Day11::SolvePart2()
{
	uint64_t numStones = 0;
	for  (int s : InitialStones)
	{
		numStones += CountStonesRec(s, 75);
		// cout << numStones << endl;
	}
	
	return to_string(numStones);
}

vector<uint64_t> Day11::Blink(uint64_t stone)
{	
	vector<uint64_t> result;
	if (stone == 0)
		result.push_back(1);
	else if (int numDigits = GetNumDigits(stone); numDigits % 2 == 0)
	{
		uint64_t left = stone / PowersOfTen[numDigits / 2];
		uint64_t right = stone % PowersOfTen[numDigits / 2];
		// cout << stone << " " << numDigits << " " << left << " " << right << endl;
		result.push_back(left);
		result.push_back(right);
	}
	else
	{
		result.push_back(stone * 2024);
	}
	return result;
}

uint64_t Day11::CountStonesRec(uint64_t stone, int num)
{
	const StoneState mem = {stone, num};
	if (num == 0)
		return 1;
	if (auto memo = StoneMemo.find(mem); memo != StoneMemo.end())
		return memo->second;
	uint64_t result = 0;
	for (uint64_t s : Blink(stone))
	{
		result += CountStonesRec(s, num - 1);
	}

	StoneMemo[mem] = result;
	return result;
}

int Day11::GetNumDigits(uint64_t stone)
{
	for(int i = 1; i <= 14; ++i)
	{
		if (stone < PowersOfTen[i])
		{
			// cout << "P10 " << stone << " " << i << endl;
			return i;
		}
	}

	cout << "digit overflow" << endl;
	return 0;
}