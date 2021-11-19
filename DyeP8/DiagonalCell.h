//DiagonalCell.h

#ifndef DIAGONAL_CELL_H
#define DIAGONAL_CELL_H

#include "LifeCell.h"

class DiagonalCell : public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int x, int y);
	virtual void UpdateCells();

private:
	int neighbors[5][2] = { {-1, -1}, {-1, +1}, {0, 0}, {+1, -1}, {+1, +1} };

public:
	DiagonalCell();
};

#endif