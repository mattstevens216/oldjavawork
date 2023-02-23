


void selectionSort(int A[], int n)
{
	for (int k = 0; k < n-1; k++)
	{
		int index = k;
		for (int i = k+1; i < n; i++)
			if (A[i] < A[index]) index = i;
		int tmp = A[k]; // swap A[k] and A[index]
		A[k] = A[index];
		A[index] = tmp;
	}
}
