#ifndef __EXE_HW2__
#define __EXE_HW2__

#include "equation.h"

//const char tavs[3];

int getAllEquationsFromUser(AllEquations* pEqs);




char* getEquFromUser(int index);
int	parseStringToVectors(Equation* pEqu,const char* str);
int	findXYZ(char tav);

#endif
