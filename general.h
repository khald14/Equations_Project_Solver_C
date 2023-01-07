#ifndef __GENERAL__
#define __GENERAL__

void printMat(float** mat, int rows, int cols);
void printVector(float* vec, int rows);
float determinantSolveMatrix3_3(float** a_mat,float* b_vec, float* res_vec);
float determinantSolveMatrix2_2(float** a_mat, float* b_vec, float* res_vec);

char* getStr();

#endif
