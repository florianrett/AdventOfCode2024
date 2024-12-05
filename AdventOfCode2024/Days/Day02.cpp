#include "Day02.h"
#include <regex>

int Day02::SolvePart1()
{
	regex numbers("[0-9]+");
	for (string line : Input)
	{
		vector<int> numberList;
		for (sregex_iterator i = sregex_iterator(line.begin(), line.end(), numbers); i != sregex_iterator(); ++i)
		{
			smatch m = *i;
			numberList.push_back(stoi(m.str()));
		}
		Data.push_back(numberList);
	}

	int numSafe = 0;
	for (vector<int> report : Data)
	{		
		if (TestSafety(GenerateDeltas(report)))
			numSafe++;
	}

	return numSafe;
}

int Day02::SolvePart2()
{
	int numSafe = 0;
	for (vector<int> report : Data)
	{
		if(TestSafety(GenerateDeltas(report)))
		{
			numSafe++;
		}
		else
		{
			for (int i = 0; i < report.size(); ++i)
			{
				vector<int> testReport = report;
				testReport.erase(testReport.begin() + i);
				if (TestSafety(GenerateDeltas(testReport)))
				{
					numSafe++;
					break;
				}
			}
		}
	}
	return numSafe;
}

vector<int> Day02::GenerateDeltas(vector<int> report)
{
	vector<int> deltas;
	deltas.reserve(report.size() - 1);
	for (int i = 0; i < report.size() - 1; ++i)
	{
		deltas.push_back(report[i + 1] - report[i]);
	}

	return deltas;
}

bool Day02::TestSafety(vector<int> const& deltas)
{
	bool isIncreasing = deltas[0] > 0;
	for (int d : deltas)
	{
		if (d > 0 != isIncreasing || d == 0 || abs(d) > 3)
		{
			return false;
		}
	}

	return true;
}
