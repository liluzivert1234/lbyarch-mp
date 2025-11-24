#include <stdlib.h>

double* cDAXPY(double A, double X[], double Y[], int size) {
	double* result = (double*)malloc(size * sizeof(double));
	int i = 0;
	for (i = 0; i < size; i++)
	{
		result[i] = A * X[i] + Y[i];
	}

	return result;
}