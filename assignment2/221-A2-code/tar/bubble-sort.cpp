//============================================================================
// Name        : bubble-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void
BubbleSort::sort(int A[], int size)			// main entry point
{
	for (int k = 1; k < size; k++) {
		bool cont = false;
		for (int j = 0; j < size - k; j++) {
			if (A[j + 1] < A[j]) {
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				cont = true;
				num_cmps++;
			}
		}
		if (!cont) break;
	}
	/* Complete this function with the implementation of bubble sort algorithm
	Record number of comparisons in variable num_cmps of class Sort
	*/
}
