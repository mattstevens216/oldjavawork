//============================================================================
// Name        : shell-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of shell sort in C++
//============================================================================
#include <iostream>
#include "sort.h"

#include <algorithm>
using namespace std;
void
ShellSort::sort(int array[], int n)
{
	int j;

	//Narrow the array by 2 everytime
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; ++i)
		{
			int temp = array[i];
			for (j = i; j >= gap && temp < array[j - gap]; j -= gap)
			{
				array[j] = array[j - gap];
				num_cmps++;
			}
			array[j] = temp;
		}
	}
	/* Complete this function with the implementation of shell sort algorithm
	Record number of comparisons in variable num_cmps of class Sort
	*/
}
