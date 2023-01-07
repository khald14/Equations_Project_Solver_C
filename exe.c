#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "general.h"
#include "exe.h"
#include "equation.h"

static const char tavs[3] = {'x','y','z'};

int getAllEquationsFromUser(AllEquations* pEqs)
{
	int count;
	char* strEqu;

	do {
		printf("Enter number of equations (1-3)\t");
		scanf("%d", &count);
	} while (count < 1 || count > 3);
	getchar();

	pEqs->count = count;
	pEqs->eqArr = (Equation**)malloc(count * sizeof(Equation*));
	if (!pEqs->eqArr)
		return 0;

	for (int i = 0; i < count; i++)
	{

		pEqs->eqArr[i] = (Equation*)malloc(sizeof(Equation));
		if (!pEqs->eqArr[i])
			return 0;
		pEqs->eqArr[i]->A = (float*)calloc(count, sizeof(float));
		if(!pEqs->eqArr[i]->A)
			return 0;
		pEqs->eqArr[i]->count = count;
		strEqu = getEquFromUser(i);
		if (!strEqu)
			return 0;
		if(!parseStringToVectors(pEqs->eqArr[i],strEqu))
			return 0;
		free(strEqu);
	}

	return 1;
}

char* getEquFromUser(int index)
{
	char* str;
	char temp[100];
	int len;

	printf("enter equation %d\t", (index + 1));
	getStr(temp, sizeof(temp));
	len = strlen(temp) + 1;
	str = (char*)malloc(len * sizeof(char));
	if (!str)
		return NULL;

	strcpy(str, temp);
	return str;
}

int	parseStringToVectors(Equation* pEqu,const char* str)
{
	float num;
	int minus = 0;

	for(int i = 0; i< pEqu->count; i++)
	{
		minus = 0;

		while (!isdigit(*str))
		{
			if (*str == '-')
				minus = 1;
			if (*str == '=')
				break;
			str++;
		}

		if(*str == '=')
			break;

		sscanf(str, "%f", &num);
		if (minus)
			num *= (-1);
		int index = strcspn(str, "*");
		str += index;
		while (!isalpha(*str))
			str++;

		int entryToVectors = findXYZ(*str);
		if (entryToVectors < 0 || entryToVectors >= pEqu->count)
			return 0;
		pEqu->A[entryToVectors] = num;

		str++;
	}

	int index = strcspn(str, "=");
	str += index;
	minus = 0;
	while (!isdigit(*str))
	{
		if (*str == '-')
			minus = 1;
		str++;
	}

	float res;
	sscanf(str, "%f",&res);
	if (minus)
		res *= (-1);
	pEqu->B = res;
	return 1;
}


int	findXYZ(char tav)
{
	for(int i = 0; i < 3; i++)
	{
		if(tavs[i] == tav)
			return i;
	}

	return -1;
}

