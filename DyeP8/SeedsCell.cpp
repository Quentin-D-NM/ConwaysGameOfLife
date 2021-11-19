//SeedsCell.cpp

#include "SeedsCell.h"

void SeedsCell::GetLivingNeighbors(int x, int y)
{
	//Moore Neighborhood
	count = 0;
	for (int i = 0; i < 9; i++)
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

void SeedsCell::UpdateCells()
{
	//same except different rules
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 78; j++)
		{
			GetLivingNeighbors(i, j);
			if (count == 2)
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

SeedsCell::SeedsCell() : LifeCell()
{
}
