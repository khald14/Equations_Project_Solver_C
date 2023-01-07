#include <stdio.h>
#include "exe.h"
#include "equation.h"
#include "solver.h"

int main()
{

	AllEquations allEq = { 0,NULL};
	Solver solve;

	if(!getAllEquationsFromUser(&allEq))
	{
		printf("Error");
		return -1;
	}

	if(!solveEquations(&allEq,&solve))
	{
		printf("Error");
		return -1;
	}
	printResults(&solve);

	freeAll(&allEq,&solve);
}
