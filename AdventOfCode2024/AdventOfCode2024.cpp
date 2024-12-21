// AdventOfCode2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "BaseSolver.h"
#include "Days/Day11.h"

int main()
{
    bool bUseTestInput = false;

    BaseSolver* Solver = new Day11();

    chrono::high_resolution_clock::time_point StartTime = chrono::high_resolution_clock::now();
    Solver->ReadInput(bUseTestInput);
    string part1 = Solver->SolvePart1();
    chrono::high_resolution_clock::time_point StartTime2 = chrono::high_resolution_clock::now();
    string part2 = Solver->SolvePart2();
    chrono::high_resolution_clock::time_point EndTime = chrono::high_resolution_clock::now();

    string Solutions = format("Puzzle Solutions are:\n"
                        "Part 1: {} ({})\n"
                        "Part 2: {} ({})\n",
                        part1, chrono::duration<float>( StartTime2 - StartTime), part2, chrono::duration<float>(EndTime - StartTime2));

    std::cout << Solutions;

    return 0;
}

