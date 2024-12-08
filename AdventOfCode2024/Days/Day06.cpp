#include "Day06.h"

void Day06::ReadInput(bool bUseTestInput)
{
	BaseSolver::ReadInput(bUseTestInput);
	Height = Input.size();
	Width = Input[0].length();
	
	for (int y = 0; y < Height; y++)
	{
		for (int x = 0; x < Width; x++)
		{
			if (Input[y][x] == '#')
			{
				Obstacles.insert(Get2dIdx(x, y));
			}
			else if (Input[y][x] == '^')
			{
				GuardX = x;
				GuardY = y;
			}
		}
	}
}

int Day06::SolvePart1()
{
	unordered_set<int> Visited;
	int currentX = GuardX;
	int currentY = GuardY;
	int dirX = 0;
	int dirY = -1;
	while (true)
	{
		Visited.insert(Get2dIdx(currentX, currentY));
		Path.insert(Get2dIdx(currentX, currentY));
		int nextX = currentX + dirX;
		int nextY = currentY + dirY;
		if (nextX >= 0 && nextY >= 0 && nextX < Width && nextY < Height)
		{
			if (Obstacles.contains(Get2dIdx(nextX, nextY)))
			{
				//rotate (0,-1) -> (1,0) -> (0,1) -> (-1,0)
				int oldDirX = dirX;
				dirX = dirY * -1;
				dirY = oldDirX;
			}
			else
			{
				currentX = nextX;
				currentY = nextY;
			}
		}
		else
		{
			break;
		}
	}
	
	return Visited.size();
}

typedef pair<int, int> DirType;
typedef pair<int, DirType> StateType;
struct state_hash
{
	std::size_t operator()(const StateType& s) const
	{
		return s.first*4095+s.second.first*31+s.second.second;
	}
};

int Day06::SolvePart2()
{
	int numPossibleObstacles = 0;
	// New obstacle must be on guard's path to affect her and create a loop
	for (int ProbeObstacle : Path)
	{
		if (ProbeObstacle == Get2dIdx(GuardX, GuardY))
			continue;
		
		// Just brute force tracing
		unordered_set<StateType, state_hash> Visited;
		Visited.clear();
		int currentX = GuardX;
		int currentY = GuardY;
		int dirX = 0;
		int dirY = -1;
		while (true)
		{
			// Detect loop if current state was encountered already
			pair<int, pair<int, int>> state = {Get2dIdx(currentX, currentY), {dirX, dirY}};
			if (Visited.contains(state))
			{
				numPossibleObstacles++;
				break;
			}
			
			Visited.insert(state);
			int nextX = currentX + dirX;
			int nextY = currentY + dirY;
			if (nextX >= 0 && nextY >= 0 && nextX < Width && nextY < Height)
			{
				if (Obstacles.contains(Get2dIdx(nextX, nextY)) || Get2dIdx(nextX, nextY) == ProbeObstacle)
				{
					//rotate (0,-1) -> (1,0) -> (0,1) -> (-1,0)
					int oldDirX = dirX;
					dirX = dirY * -1;
					dirY = oldDirX;
				}
				else
				{
					currentX = nextX;
					currentY = nextY;
				}
			}
			else
			{
				break;
			}
		}
	}
	return numPossibleObstacles;
}
