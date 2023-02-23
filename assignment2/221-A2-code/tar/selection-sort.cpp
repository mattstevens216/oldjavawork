//============================================================================
// Name        : selection-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of selection sort in C++
//============================================================================

#include "sort.h"
#include <iostream>

void
SelectionSort::sort(int arr[], int n)				// main entry point
{
	int pos_min, temp;

	for (int i = 0; i < n - 1; i++)
	{
		pos_min = i;//set pos_min to the current index of array

		for (int j = i + 1; j < n; j++)
		{

			if (arr[j] < arr[pos_min]) {
				pos_min = j;
				num_cmps++;
			}
			//pos_min will keep track of the index that min is in, this is needed when a swap happens
		}

		//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
		if (pos_min != i)
		{
			temp = arr[i];
			arr[i] = arr[pos_min];
			arr[pos_min] = temp;
		}
	}
	/* Complete this function with the implementation of selection sort algorithm
	Record number of comparisons in variable num_cmps of class Sort
	*/
}
