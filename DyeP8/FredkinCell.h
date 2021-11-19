//FredkinCell.h

#ifndef FREDKIN_CELL_H
#define FREDKIN_CELL_H

#include "LifeCell.h"

class FredkinCell : public LifeCell
{
protected: 
	virtual void GetLivingNeighbors(int x, int y);
	virtual void UpdateCells();

private:
	int neighbors[5][2] = { {-1, 0}, {0, -1}, {0, 0}, {0, +1}, {+1, 0} };

public:
	FredkinCell();
};



#endif
