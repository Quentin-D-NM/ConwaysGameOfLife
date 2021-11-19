//FredkinCell.cpp

#include "FredkinCell.h"

void FredkinCell::GetLivingNeighbors(int x, int y)
{
	//This is a VonNeumann neighborhood - 4 neighbors only
	//up, down, left, and right
	count = 0;
	for (int i = 0; i < 5; i++)
	{
		//make sure that the check is not of itself also check if valid x y points
		bool check = (neighbors[i][0] == 0 && neighbors[i][1] == 0) ? false : true;
		bool validx = (x + neighbors[i][0] >= 0 && x + neighbors[i][0] < 45) ? true : false;
		bool validy = (y + neighbors[i][1] >= 0 && y + neighbors[i][1] < 78) ? true : false;
		if (check && validx && validy)
		{
			if (cell[x + neighbors[i][0]][y + neighbors[i][1]] == '*')
			{
				count++;
			}
		}
	}
}

void FredkinCell::UpdateCells()
{
	//same as conway except the rules are different
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 78; j++)
		{
			GetLivingNeighbors(i, j);
			if (cell[i][j] == '*')
			{
				if((count == 0) || (count == 2) || (count == 4))
				{
					nextCellState[i][j] = '.';
				}
				else
				{
					nextCellState[i][j] = '*';
				}
			}
			//rules for dead cells
			else
			{
				if (count == 1 || count == 3)
				{
					nextCellState[i][j] = '*';
				}
				else
				{
					nextCellState[i][j] = '.';
				}
			}
		}
	}
}

FredkinCell::FredkinCell() : LifeCell()
{
}
