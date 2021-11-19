//LifeCell.cpp

#include "LifeCell.h"
#include <fstream>
#include <sstream>

void LifeCell::InitializeBoard()
{
    //open an input filestream(ofstream) and check it 
    //set bOpen false if not
    //read the pattern file if ok.
    //close the file 
    //set bOpen true
    fstream inputFile; 
    string line;
    int count = 0;

    switch (pattern)
    {
    case 0:
        inputFile.open("gliderGunner.txt");
        break;
    case 1:
        inputFile.open("largediamonds.txt");
        break;
    case 2:
        inputFile.open("trapezoids.txt");
        break;
    case 3:
        inputFile.open("cutBlocks.txt");
        break;
    case 4:
        inputFile.open("blocks.txt");
        break;
    }

    while (inputFile.is_open() && !inputFile.eof())
    {
        getline(inputFile, line);
        if (count > 0)
        {
            int col = 0;
            for (char c : line)
            {
                cell[count - 1][col] = c;
                col++;
            }
        }
        count++;
    }

}

void LifeCell::SetNextState()
{
    for (int i = 0; i < 45; i++)
    {
        for (int j = 0; j < 78; j++)
        {
            cell[i][j] = nextCellState[i][j];
        }
    }
    //also a 2 -d assignment of nextcellstate into cell
}

LifeCell::LifeCell()
{
    //Initialize the grid to '.' and nextcellstate
    for (int i = 0; i < 45; i++)
    {
        for (int j = 0; j < 78; j++)
        {
            cell[i][j] = '.';
            nextCellState[i][j] = '.';
        }
    }
}

void LifeCell::SetPattern(int pat)
{
    pattern = pat;
    InitializeBoard();
}

void LifeCell::UpdateBoard()
{
    UpdateCells();
    SetNextState();
}

string LifeCell::PrintBoard()
{
    stringstream ss; 
    for (int i = 0; i < 45; i++)
    {
        for (int j = 0; j < 78; j++)
        {
            ss << cell[i][j]; 
        }
        ss << "\n";
    }
    return ss.str();
}

void LifeCell::Clear()
{
    for (int i = 0; i < 45; i++)
    {
        for (int j = 0; j < 78; j++)
        {
            cell[i][j] = 0;
        }
    }
    //To be defined later
}
