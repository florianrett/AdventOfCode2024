#include "RegexHelper.h"

vector<string> RegexHelper::FindAllMatches(string pattern, string search)
{
    vector<string> result;
    regex rex(pattern);
    for (smatch match; regex_search(search, match, rex);)
    {
        result.push_back(match.str());
        search = match.suffix();
    }

    return result;
}
