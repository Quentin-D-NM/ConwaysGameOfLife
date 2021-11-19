//ModifiedFredkin.cpp

#include "ModifiedFredkin.h"

void ModifiedFredkin::GetLivingNeighbors(int x, int y)
{
	//VonNeumann and then Moore neighborhood
	//check the age, and if >= 2, Moore
	//otherwise Vonneumann
	//int neighbors[9][2]; 
	count = 0;
	if (age[x][y] >= 2)
	{
		for (int i = 0; i < 9; i++)
		{
			//make sure that the check is not of itself also check if valid x y points
			bool check = (neighborsConway[i][0] == 0 && neighborsConway[i][1] == 0) ? false : true;
			bool validx = (x + neighborsConway[i][0] >= 0 && x + neighborsConway[i][0] < 45) ? true : false;
			bool validy = (y + neighborsConway[i][1] >= 0 && y + neighborsConway[i][1] < 78) ? true : false;
			if (check && validx && validy)
			{
				if (cell[x + neighborsConway[i][0]][y + neighborsConway[i][1]] == '*')
				{
					count++;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			//make sure that the check is not of itself also check if valid x y points
			bool check = (neighborsFredkin[i][0] == 0 && neighborsFredkin[i][1] == 0) ? false : true;
			bool validx = (x + neighborsFredkin[i][0] >= 0 && x + neighborsFredkin[i][0] < 45) ? true : false;
			bool validy = (y + neighborsFredkin[i][1] >= 0 && y + neighborsFredkin[i][1] < 78) ? true : false;
			if (check && validx && validy)
			{
				if (cell[x + neighborsFredkin[i][0]][y + neighborsFredkin[i][1]] == '*')
				{
					count++;
				}
			}
		}
	}
}

void ModifiedFredkin::UpdateCells()
{
	//check age, if >= 2 make it a conway cell, 
	//then apply the conway rules
	//else apply the fredkin rules
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 78; j++)
		{
			GetLivingNeighbors(i, j);
			if (cell[i][j] == '*')
			{
				if (((count == 0) || (count == 2) || (count == 4)) && age[i][j] < 2)
				{
					nextCellState[i][j] = '.';
				}
				else if (age[i][j] < 2)
				{
					nextCellState[i][j] = '*';
					age[i][j]++;
				}
				else if (age[i][j] >= 2 && (count < 2 || count > 3))
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
				if ((count == 1 || count == 3))
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

ModifiedFredkin::ModifiedFredkin() :FredkinCell()
{
}

void ModifiedFredkin::ClearAge()
{
	for (int i = 0; i < 45; i++)
	{
		for (int j = 0; j < 78; j++)
		{
			age[i][j] = 0;
		}
	}
}
