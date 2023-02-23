//============================================================================
// Name        : insertion-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"
using namespace std;
void
InsertionSort::sort(int arr[], int length)				// main entry point
{
	int i, j, tmp;
	for (i = 1; i < length; i++) {
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
			num_cmps++;
		}//end of while loop
		
	}//end of for loop

}
