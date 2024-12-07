// AdventOfCode2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BaseSolver.h"
#include "Days/Day05.h"

int main()
{
    bool bUseTestInput = false;

    BaseSolver* Solver = new Day05();

    Solver->ReadInput(bUseTestInput);
    int part1 = Solver->SolvePart1();
    int part2 = Solver->SolvePart2();

    std::cout << "Puzzle Solutions are:\nPart 1: " << part1 << "\nPart 2: " << part2 << std::endl;
}

