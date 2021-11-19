#ifndef MODIFIED_FREDKIN_H
#define MODIFIED_FREDKIN_H

#include "FredkinCell.h"

class ModifiedFredkin : public FredkinCell
{
protected: 
	int age[ROWS][COLS]{ 0 };
	virtual void GetLivingNeighbors(int x, int y);
	virtual void UpdateCells();
private: 
	int neighborsFredkin[5][2] = { {-1, 0}, {0, -1}, {0, 0}, {0, +1}, {+1, 0} };
	int neighborsConway[9][2] = { {-1, -1}, {-1, 0}, {-1, +1}, {0, -1}, {0, 0}, {0, +1}, {+1, -1}, {+1, 0}, {+1, +1} };
public:
	ModifiedFredkin();
	void ClearAge();
};

#endif