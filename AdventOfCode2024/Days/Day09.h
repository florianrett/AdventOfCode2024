#pragma once
#include <stack>

#include "../BaseSolver.h"

class Day09 : public BaseSolver
{
public:
	void ReadInput(bool bUseTestInput) override;
	string SolvePart1() override;
	string SolvePart2() override;

private:
	vector<int> Diskmap;
	
};

struct Diskspace
{
	int ID;
	int size;

	Diskspace(int ID, int size) : ID(ID), size(size) {}
};
