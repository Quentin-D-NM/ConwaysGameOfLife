//Quentin Dye - qdye@cnm.edu
//The Game of Life with Polymorphism

//Driver.cpp

#include <iostream>
#include "LifeCell.h"
#include "Conway.h"
#include "FredkinCell.h"
#include "ModifiedFredkin.h"
#include "SeedsCell.h"
#include "DiagonalCell.h"
#include "Functions.h"
#include <windows.h>


using namespace std;

int main()
{

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);

	//create polymorphic array
	LifeCell* pLife[5];
	ConwayCell	con;
	FredkinCell fred;
	ModifiedFredkin modfred;
	SeedsCell seeds;
	DiagonalCell diagonal;

	pLife[0] = &con;
	pLife[1] = &fred;
	pLife[2] = &modfred;
	pLife[3] = &seeds;
	pLife[4] = &diagonal;

	int lifecount{ 0 };
	int config{ 0 };
	int pattern;
	char answer{ 'y' };
	int lifeCount{ 0 };

	cout << header();

	do
	{
		config = UserChoosesAnImplementation();
		config--;

		pattern = UserChoosesInitialPattern();
		if (pattern == 5)
		{
			draw();
		}

		//set pattern into object
		pLife[config]->SetPattern(pattern);

		do
		{
			pLife[config]->UpdateBoard();
			cout << pLife[config]->PrintBoard() << flush;
			Sleep(200);
			system("cls");
			lifeCount++;
		} while (lifeCount < 50);
		pLife[config]->Clear();
		ModifiedFredkin* mfc = dynamic_cast<ModifiedFredkin*>(pLife[config]);
		if (mfc != nullptr)
		{
			mfc->ClearAge();
		}
		lifeCount = 0;
		cout << "\n\nDo you want to run another simulation?(y or n) ";
		cin >> answer;

	} while (answer == 'y');

	return 0;
}