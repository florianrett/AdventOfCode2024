#include "Day03.h"
#include <regex>

int Day03::SolvePart1()
{
	int result = 0;
	for (string line : Input)
	{
		regex mul("mul\\([0-9]+,[0-9]+\\)");
		for (sregex_iterator i = sregex_iterator(line.begin(), line.end(), mul); i != sregex_iterator(); i++)
		{
			string ins = i->str();
			int pos = static_cast<int>(ins.find(','));
			int n1 = stoi(ins.substr(4, pos));
			int n2 = stoi(ins.substr(pos + 1, ins.length()));
			result += n1 * n2;
		}
	}
	return result;
}

int Day03::SolvePart2()
{
	int result = 0;
	bool isEnabled = true;
	for (string line : Input)
	{
		regex find_mul("mul\\([0-9]+,[0-9]+\\)");
		regex find_do("do\\(\\)");
		regex find_dont(R"(don't\(\))");
		regex find_ins(R"((mul\([0-9]+,[0-9]+\))|(do\(\))|(don't\(\)))");

		for (smatch match; regex_search(line, match, find_ins);)
		{
			string ins = match.str();
			if(ins.substr(0, 3) == "mul")
			{
				if (isEnabled)
				{
					int pos = static_cast<int>(ins.find(','));
					int n1 = stoi(ins.substr(4, pos));
					int n2 = stoi(ins.substr(pos + 1, ins.length()));
					result += n1 * n2;
				}
			}
			else if (ins.substr(0, 3) == "do(")
			{
				isEnabled = true;
			}
			else if (ins.substr(0, 3) == "don")
			{
				isEnabled = false;
			}
			line = match.suffix();
		}
	}
	return result;
}
