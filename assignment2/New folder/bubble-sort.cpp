
void bubbleSort(int A[], int n){
	for (int k = 1; k < n; k++) {
		bool cont = false;
		for (int j = 0; j < n - k; j++)
			if (A[j+1] < A[j]) {
				int tmp = A[j]; // swap A[j] and A[j+1]
				A[j] = A[j+1];
				A[j+1] = tmp;
				cont = true;
			}
		if (!cont) break; // stop sorting
	}
}
