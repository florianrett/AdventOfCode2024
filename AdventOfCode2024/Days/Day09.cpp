#include "Day09.h"

#include <assert.h>

void Day09::ReadInput(bool bUseTestInput)
{
	BaseSolver::ReadInput(bUseTestInput);

	for (char c : Input[0])
	{
		Diskmap.push_back(c - '0');
	}
}

string Day09::SolvePart1()
{
	vector<int> Disk;
	int ID = 0;
	bool bIsFile = true;
	for (int i : Diskmap)
	{
		for (int j = 0; j < i; ++j)
		{
			Disk.push_back(bIsFile ? ID : -1);
			// cout << Disk.back();
		}
		if (bIsFile)
			ID++;
		bIsFile = !bIsFile;
	}
	// cout << endl;
		
	long long checksum = 0;
	for (int i = 0; i < Disk.size(); ++i)
	{
		if (Disk[i] == -1)
		{
			Disk[i] = Disk.back();
			Disk.pop_back();
			assert(Disk[i] > -1);
		}
		// cout << Disk[i];
		checksum += Disk[i] * i;

		while(Disk.back() == -1)
		{
			Disk.pop_back();
		}
	}
	
	return to_string(checksum);
}

string Day09::SolvePart2()
{
	vector<Diskspace> Data;
	for(int i = 0; i < Diskmap.size(); ++i)
	{
		if (i % 2 == 0)
		{
			Data.emplace_back(i / 2, Diskmap[i]);		
		}
		else
		{
			Data.emplace_back(-1, Diskmap[i]);
		}
	}

	for (int i = Data.size() - 1; i >= 0; --i)
	{
		if (Data[i].ID >= 0)
		{
			for (int j = 0; j < i; ++j)
			{
				if (Data[j].ID == -1 && Data[j].size >= Data[i].size)
				{
					Data[j].size -= Data[i].size;
					Data.emplace(Data.begin() + j, Data[i]);
					Data[i + 1].ID = -1;
					++i; //increase index to account for the just added element
					break;
				}
			}
		}

		// cout << "iteration index " << i << endl;
		// for (Diskspace d : Data)
		// {
		// 	for (int num = 0; num < d.size; ++num)
		// 		cout << (d.ID >= 0 ? to_string(d.ID) : ".");
		// }
		// cout << endl;
	}
		
	long long checksum = 0;
	int position = 0;
	for (const Diskspace& d : Data)
	{
		if (d.ID >= 0)
		{
			checksum += static_cast<long long>(d.size) * d.ID * position;
			//add triangle number * ID to account for block position increases inside the file
			checksum += static_cast<long long>(d.size) * (d.size - 1) / 2 * d.ID;
			// cout << d.ID << " " << d.size << " " << checksum << endl;
		}

		position += d.size;
	}
	
	
	return to_string(checksum);
}
