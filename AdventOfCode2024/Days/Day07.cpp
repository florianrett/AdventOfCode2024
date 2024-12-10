#include "Day07.h"
#include <regex>

void Day07::ReadInput(bool bUseTestInput)
{
	BaseSolver::ReadInput(bUseTestInput);

	regex num("[0-9]+");
	for (string line : Input)
	{
		vector<long long> eq;
		for (smatch match; regex_search(line, match, num);)
		{
			// cout << match.str() << endl;
			eq.push_back(stoll(match.str()));
			
			line = match.suffix();
		}
		Equations.push_back(eq);
	}
}

string Day07::SolvePart1()
{
	long long result = 0;
	for (vector<long long> eq : Equations)
	{
		unordered_set<long long> values({eq[1]});
		for (int i = 2; i < eq.size(); ++i)
		{
			// cout << "Equation param " << i << ": " << eq[i] << endl;
			unordered_set<long long> newValues;
			newValues.clear();
			for (long long v : values)
			{
				if (v > eq[0])
					continue;
				// cout << "value: " << v << endl;
				newValues.insert(v + eq[i]);
				newValues.insert(v * eq[i]);
			}
			values = newValues;
		}

		if (values.contains(eq[0]))
			result += eq[0];
	}
	
	return to_string(result);
}

string Day07::SolvePart2()
{
	long long result = 0;
	for (vector<long long> eq : Equations)
	{
		unordered_set<long long> values({eq[1]});
		for (int i = 2; i < eq.size(); ++i)
		{
			// cout << "Equation param " << i << ": " << eq[i] << endl;
			unordered_set<long long> newValues;
			newValues.clear();
			for (long long v : values)
			{
				if (v > eq[0])
					continue;
				// cout << "value: " << v << endl;
				newValues.insert(v + eq[i]);
				newValues.insert(v * eq[i]);
				newValues.insert(stoll(to_string(v) + to_string(eq[i])));
			}
			values = newValues;
		}

		if (values.contains(eq[0]))
			result += eq[0];
	}
	
	return to_string(result);
}
