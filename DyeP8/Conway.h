//Conway.h

#ifndef CONWAY_CELL_H
#define CONWAY_CELL_H

#include "LifeCell.h"

class ConwayCell : public LifeCell
{
protected : 
	virtual void GetLivingNeighbors(int x, int y); 
	virtual void UpdateCells();

private: 
	int neighbors[9][2] = { {-1, -1}, {-1, 0}, {-1, +1}, {0, -1}, {0, 0}, {0, +1}, {+1, -1}, {+1, 0}, {+1, +1} };

public: 
	ConwayCell();
};



#endif