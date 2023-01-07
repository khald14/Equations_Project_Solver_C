#include <stdlib.h>
#include <stdio.h>

#include "general.h"
#include "equation.h"
#include "solver.h"


int solveEquations(AllEquations* pEqs,Solver* pSolver)
{
	if(!buildSolver(pEqs,pSolver))
		return 0;
	solve(pSolver);
	return 1;
}

void solve(Solver* pSolver)
{
	if (pSolver->count == 3)
		pSolver->Detrmin = determinantSolveMatrix3_3(pSolver->A_Mat, pSolver->B_Vec,pSolver->X_Vec);
	else if (pSolver->count == 2)
		pSolver->Detrmin = determinantSolveMatrix2_2(pSolver->A_Mat, pSolver->B_Vec, pSolver->X_Vec);
	else {
		pSolver->Detrmin = pSolver->A_Mat[0][0];
		if(pSolver->Detrmin!= 0)
			pSolver->X_Vec[0] = pSolver->B_Vec[0]/ pSolver->Detrmin;
	}
}

int buildSolver(AllEquations* pEqs,Solver* pSolver)
{
	int count = pEqs->count;
	pSolver->count = count;
	pSolver->A_Mat = (float**)calloc(count, sizeof(float*));
	if (!pSolver->A_Mat)
		return 0;

	pSolver->B_Vec = (float*)calloc(count, sizeof(float));
	if (!pSolver->B_Vec)
		return 0;

	pSolver->X_Vec = (float*)calloc(count, sizeof(float));
	if (!pSolver->X_Vec)
		return 0;

	for (int i = 0; i < count; i++)
	{
		pSolver->A_Mat[i] = pEqs->eqArr[i]->A;
		pSolver->B_Vec[i] = pEqs->eqArr[i]->B;
	}
	return 1;
}

void printResults(Solver* pSolver)
{
	printf("\n---------- A  Matrix -----------\n\n");
	printMat(pSolver->A_Mat, pSolver->count, pSolver->count);

	printf("\n----------- Determinant ----------- \n\n");
	printf("%.3f\n", pSolver->Detrmin);

	printf("\n---------- B  Vector -----------\n\n");
	printVector(pSolver->B_Vec, pSolver->count);

	if (pSolver->Detrmin == 0)
		printf("There is no solution for equation\n");
	else {
		printf("\n---------- X  Vector -----------\n\n");
		for(int i = 0; i < pSolver->count; i++)
			printf("%c = %.3f\n",tavs[i],pSolver->X_Vec[i]);
	}
}

void freeAll(AllEquations* pEqs,Solver* pSolver)
{
	for (int i = 0; i < pEqs->count; i++)
	{
		free(pEqs->eqArr[i]->A);
		free(pEqs->eqArr[i]);
	}
	free(pEqs->eqArr);

	free(pSolver->A_Mat);
	free(pSolver->B_Vec);
	free(pSolver->X_Vec);
}

