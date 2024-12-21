#pragma once

#include <regex>
#include <string>
#include <vector>
using namespace std;

struct RegexHelper
{
    static vector<string> FindAllMatches(string pattern,  string search);
};
