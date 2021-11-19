//Functions.cpp

#include "Functions.h"
#include <windows.h>

using namespace std;

void WriteInstructions()
{
}

int UserChoosesAnImplementation()
{
    //Show user the choices of cell types and 
    //ask them to select
    int choice = 0;
    cout << "\n1. Conway Cell\n";
    cout << "2. Fredkin Cell\n";
    cout << "3. Modified Fredkin Cell\n";
    cout << "4. Seed Cell\n";
    cout << "5. Diagonal Cell\n";
    cout << "\nPlease choose a cell type 1-5: ";
    cin >> choice;
    return choice;
}

int UserChoosesInitialPattern()
{
    int option = 0;
    cout << "\n1.Glider Gunner\n";
    cout << "2.Large Diamonds\n";
    cout << "3.Trapezoids\n";
    cout << "4.Cut Blocks\n";
    cout << "5.Blocks\n";
    //cout << "6.Draw your own\n";
    cout << "\nPlease choose a pattern to start with 1-5: ";
    cin >> option;
    //show the user the choices of patterns and 
    return option -1;
}

string header()
{
    string header = "Quentin Dye - qdye@cnm.edu\nCIS 2275 C++ Programming II\nThe Game of Life - Inheritance and Polymorphism\n";
    return header;
}

char** draw()
{
    POINT point;
    char** pattern = new char* [45];
    for (int i = 0; i < 45; i++)
    {
        pattern[i] = new char[78];
        for (int j = 0; j < 78; j++)
        {
            pattern[i][j] = '.';
        }
    }
    updateScreen(pattern);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        if (WM_LBUTTONDOWN && GetCursorPos(&point))
        {
            pattern[point.x][point.y] = '*';
            updateScreen(pattern);
        }
    }

    return pattern;
}

void updateScreen(char **patter)
{
    cout << flush;
    for (int i = 0; i < 45; i++)
    {
        for (int j = 0; j < 78; j++)
        {
            cout << patter[i][j];
        }
        cout << "\n";
    }
    cout << "\nPress ESC to exit.";
}