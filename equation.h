#ifndef __EQU__
#define __EQU__

static const char tavs[3];

typedef struct
{
	int		count; //number or coefficients
	float*	A; // coefficients of x,y,z (in that order)
	float	B; //The free number on the right side;
}Equation;

typedef struct
{
	int 		count;	//number or equations
	Equation** 	eqArr;	//All equations
} AllEquations;



#endif
