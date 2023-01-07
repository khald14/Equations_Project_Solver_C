#include <stdio.h>
#include <string.h>

#include "general.h"


void printMat(float** mat, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%.3f\t", mat[i][j]);
		printf("\n");
	}
}

void printVector(float* vec, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		printf("%5.3f", vec[i]);
		printf("\n");
	}

}


float determinantSolveMatrix2_2(float** a_mat, float* b_vec, float* res_vec)
{
	float inverse[2][2];

	float determinant = a_mat[0][0] * a_mat[1][1] - a_mat[1][0] * a_mat[0][1];
	inverse[0][0] = a_mat[1][1] / determinant;
	inverse[1][1] = a_mat[0][0] / determinant;
	inverse[0][1] = -a_mat[0][1] / determinant;
	inverse[1][0] = -a_mat[1][0] / determinant;

	res_vec[0] = inverse[0][0] * b_vec[0] + inverse[0][1] * b_vec[1];
	res_vec[1] = inverse[1][0] * b_vec[0] + inverse[1][1] * b_vec[1];

	return determinant;
}

float determinantSolveMatrix3_3(float** a_mat, float* b_vec, float* res_vec)
{
	float determinant=0;
	float inverse[3][3];
	for (int i = 0; i<3; i++)
		determinant = determinant + 
			(a_mat[0][i] * (a_mat[1][(i + 1) % 3] * a_mat[2][(i + 2) % 3] - a_mat[1][(i + 2) % 3]
			* a_mat[2][(i + 1) % 3]));

	if (determinant == 0)
		return 0;

	float invdet = 1 / determinant;

	inverse[0][0] = (a_mat[1][1] * a_mat[2][2] - a_mat[2][1] * a_mat[1][2]) * invdet;
	inverse[0][1] = (a_mat[0][2] * a_mat[2][1] - a_mat[0][1] * a_mat[2][2]) * invdet;
	inverse[0][2] = (a_mat[0][1] * a_mat[1][2] - a_mat[0][2] * a_mat[1][1]) * invdet;
	inverse[1][0] = (a_mat[1][2] * a_mat[2][0] - a_mat[1][0] * a_mat[2][2]) * invdet;
	inverse[1][1] = (a_mat[0][0] * a_mat[2][2] - a_mat[0][2] * a_mat[2][0]) * invdet;
	inverse[1][2] = (a_mat[1][0] * a_mat[0][2] - a_mat[0][0] * a_mat[1][2]) * invdet;
	inverse[2][0] = (a_mat[1][0] * a_mat[2][1] - a_mat[2][0] * a_mat[1][1]) * invdet;
	inverse[2][1] = (a_mat[2][0] * a_mat[0][1] - a_mat[0][0] * a_mat[2][1]) * invdet;
	inverse[2][2] = (a_mat[0][0] * a_mat[1][1] - a_mat[1][0] * a_mat[0][1]) * invdet;


	for (int i = 0; i < 3; i++) {
		res_vec[i] = 0;
		for (int j = 0; j < 3; j++)
			res_vec[i] += inverse[i][j] * b_vec[j];
	}
		
	return determinant;
}

char* getStr(char* buf, size_t size)
{
	if (buf != NULL && size > 0)
	{
		if (fgets(buf, size, stdin))
		{
			buf[strcspn(buf, "\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;
}
