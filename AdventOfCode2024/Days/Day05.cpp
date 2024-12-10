#include "Day05.h"

void Day05::ReadInput(bool bUseTestInput)
{
	BaseSolver::ReadInput(bUseTestInput);

	bool parsePageOrder= true;
	for (const string& line : Input)
	{
		if (line.empty())
			parsePageOrder = false;
		else if (parsePageOrder)
		{
			int first = stoi(line.substr(0, 2));
			int second = stoi(line.substr(3, 2));

			if (!PageOrders.contains(first))
				PageOrders[first] = unordered_set<int> {second};

			else
			{
				PageOrders[first].insert(second);
			}
		}
		else
		{
			vector<int> update;
			for (int i = 0; i < line.length(); i += 3)
			{
				update.push_back(stoi(line.substr(i, 2)));
			}
			Updates.push_back(update);
		}
	}

	// for (auto page : PageOrders)
	// {
	// 	cout << "Page orders for page " << page.first << endl;
	// 	for (int order : page.second)
	// 	{
	// 		cout << order << endl;
	// 	}
	// }
}

string Day05::SolvePart1()
{
	int sum = 0;
	for (vector<int> update : Updates)
	{
		unordered_set<int> prevPages;
		bool isValid = true;
		for (int page : update)
		{
			for (int prev : prevPages)
			{
				// cout << page << " " << prev << endl;
				if (PageOrders[page].contains(prev))
				{
					// cout << "Page " << page << " broken by rule " << prev << endl;
					isValid = false;
					break;
				}
			}
			if (!isValid)
				break;
			prevPages.insert(page);
		}
		if (isValid)
		{
			// find middle page and add to sum
			int middle = update[floorl(update.size()  / 2)];
			// cout << "valid middle number: " << middle << endl;
			sum += middle;
		}
		else
		{
			IncorrectUpdates.push_back(update);
		}
	}

	return to_string(sum);
}

string Day05::SolvePart2()
{
	int sum = 0;

	for(vector<int> update : IncorrectUpdates)
	{
		unordered_set<int> pages(update.begin(), update.end());
		vector<int> correctOrder;
		while (!pages.empty())
		{
			for (int page : pages)
			{
				bool isValid = true;
				for (int prev : pages)
				{
					if (PageOrders[prev].contains(page))
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					correctOrder.push_back(page);
					// cout << page << endl;
					pages.erase(page);
					break;
				}
			}
		}

		int middle = correctOrder[floorl(correctOrder.size()  / 2)];
		// cout << "Middle: " << middle << endl;
		sum += middle;
	}
	
	return to_string(sum);
}
