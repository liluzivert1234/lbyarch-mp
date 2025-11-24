#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

extern void asmDAXPY(double A, double* X, double* Y, int size, double* result);
double getTimeInMs();

int main(int argc, char* argv[]) {
	// constants that I want to set myself
	double A = 2.0;
	int size = 2 << 28;
	int sampleResultSize = 10;
	int timingRuns = 30;

	// timing stuff
	double start = 0;
	double end = 0;
	double totalTime = 0;
	double averageC = 0;
	double averageASM = 0;

	//result stuff
	double* result1 = 0;
	double* result2 = 0;

	// large arrays :((
	double* X = (double*)malloc(size * sizeof(double));
	double* Y = (double*)malloc(size * sizeof(double));

	// generate random data to calculate
	for (int i = 0; i < size; i++) {
		X[i] = (double)(rand() % 1000) / 10.0;
		Y[i] = (double)(rand() % 1000) / 10.0;
	}

	for (int i = 0; i < timingRuns; i++) {
		//double* result1 = (double*)malloc(size * sizeof(double));
		start = getTimeInMs();
		result1 = cDAXPY(A, X, Y, size);
		end = getTimeInMs();
		totalTime = end - start;

		// print sample results
		printf("Result of cDAXPY:\n");
		for (int i = 0; i < sampleResultSize; i++) {
			printf("result[%d] = %f\n", i, result1[i]);
		}
		free(result1);

		printf("\nC DAXPY time: %.4f ms\n\n", totalTime);
		// add totalTime to average C
		averageC += totalTime;

		// Dont forget to free the memory stuff

		result2 = (double*)malloc(size * sizeof(double));
		start = getTimeInMs();
		asmDAXPY(A, X, Y, size, result2);
		end = getTimeInMs();
		totalTime = end - start;

		printf("Result of asmDAXPY:\n");
		for (int i = 0; i < sampleResultSize; i++) {
			printf("result[%d] = %f\n", i, result2[i]);
		}
		free(result2);

		printf("\nx86 asm DAXPY time: %.4f ms\n\n", totalTime);
		// add totalTime to average ASM
		averageASM += totalTime;
	}
	free(X);
	free(Y);
	averageC = averageC / timingRuns;
	averageASM = averageASM / timingRuns;
	printf("C average DAXPY time: %.4f ms\n", averageC);
	printf("x86 ASM average DAXPY time: %.4f ms\n", averageASM);
	return 0;
}

double getTimeInMs() {
	LARGE_INTEGER freq, counter;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&counter);
	return (double)counter.QuadPart * 1000.0 / (double)freq.QuadPart;
}