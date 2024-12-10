#include "Day01.h"

string Day01::SolvePart1()
{
	for (string line : Input)
	{
		string left = line.substr(0, line.find(" "));
		string right = line.substr(line.rfind(" "), line.length());
		//cout << left << right << endl;

		leftColumn.push_back(stoi(left));
		rightColumn.push_back(stoi(right));

		sort(leftColumn.begin(), leftColumn.end());
		sort(rightColumn.begin(), rightColumn.end());

	}

	int difference = 0;
	for (int i = 0; i < leftColumn.size(); ++i)
	{
		difference += abs(leftColumn[i] - rightColumn[i]);
	}

    return to_string(difference);
}

string Day01::SolvePart2()
{
	unordered_map<int, int> Counter;
	for (int i : rightColumn)
	{
		Counter[i]++;
	}
	int similarityScore = 0;
	for (int i : leftColumn)
	{
		similarityScore += i * Counter[i];
	}

    return to_string(similarityScore);
}
