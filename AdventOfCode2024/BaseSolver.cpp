#include "BaseSolver.h"
#include <fstream>


BaseSolver::BaseSolver()
{
}

BaseSolver::~BaseSolver()
{
}

void BaseSolver::ReadInput(bool bUseTestInput)
{
	fstream inputFile;
	inputFile.open(bUseTestInput ? "TestInput.txt" : "PuzzleInput.txt");
	if (inputFile.is_open())
	{
		string line;
		while (std::getline(inputFile, line))
		{
			Input.push_back(line);
		}
	}
	else
	{
		cout << "Input File couldn't be opened!\n";
	}	
}

string BaseSolver::SolvePart1()
{
	return "";
}

string BaseSolver::SolvePart2()
{
	return "";
}
