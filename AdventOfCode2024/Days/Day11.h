#pragma once
#include "../BaseSolver.h"

typedef pair<uint64_t, int> StoneState;
struct stonememo_hash
{
	std::size_t operator()(const StoneState& s) const
	{
		return s.first+s.second;
	}
};

class Day11 : public BaseSolver
{
public:
	void ReadInput(bool bUseTestInput) override;
	string SolvePart1() override;
	string SolvePart2() override;

private:
	vector<int> InitialStones;
	vector<uint64_t> Blink(uint64_t stone);
	uint64_t CountStonesRec(uint64_t stone, int num);
	int GetNumDigits(uint64_t stone);
	vector<uint64_t> PowersOfTen = {0,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000,
		10000000000,
		100000000000,
		1000000000000,
		10000000000000,
		100000000000000,
		1000000000000000,
		10000000000000000,
		100000000000000000,
		1000000000000000000};
	unordered_map<StoneState, uint64_t, stonememo_hash> StoneMemo;

	
};

