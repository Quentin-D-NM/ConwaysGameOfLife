//Conway.cpp

#include "Conway.h"

void ConwayCell::GetLivingNeighbors(int x, int y)
{
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
	//there are some clever ways to do this.
	//Check 
}

void ConwayCell::UpdateCells()
{
	//Apply the rules to each cell
	//loop throught each cell on the grid
	//within for loop:
	//GetLivingNeighbors(i, j);
	//apply rules 
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 78; j++)
		{
			GetLivingNeighbors(i, j);
			if (cell[i][j] == '*')
			{
				if (count < 2 || count > 3)
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
				if (count == 3)
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

ConwayCell::ConwayCell() : LifeCell()
{
}
