//Functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>

using namespace std;

void WriteInstructions();
int UserChoosesAnImplementation();
int UserChoosesInitialPattern();
string header();
char** draw();
void updateScreen(char** patter);


#endif
