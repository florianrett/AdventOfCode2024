#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class BaseSolver abstract
{
public:
	BaseSolver();

	virtual ~BaseSolver();

	virtual void ReadInput(bool bUseTestInput = false);

	virtual int SolvePart1();

	virtual int SolvePart2();

protected:
	vector<string> Input;
};

