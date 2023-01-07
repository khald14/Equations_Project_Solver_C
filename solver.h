#ifndef SOLVER_H_
#define SOLVER_H_



typedef struct
{
	int count;
	float**		A_Mat;
	float*		B_Vec;
	float		Detrmin;
	float*		X_Vec;
}Solver;


int  buildSolver(AllEquations* pEqs,Solver* pSolver);
void solve(Solver* pSolver);
int  solveEquations(AllEquations* pEqs,Solver* pSolver);
void printResults(Solver* pSolver);
void freeAll(AllEquations* pEqs,Solver* pSolver);


#endif /* SOLVER_H_ */
