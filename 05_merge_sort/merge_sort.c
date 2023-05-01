#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int p, int q, int r); 
void sort(int arr[], int start, int end);
void printArray(int array[], int size); 

int main()
{
	int arr[] = {-2, 45, 0, 11, -9};
	sort(arr, 0, 4);
	printArray(arr, 5);
}


void sort(int arr[], int start, int end)
{
	if(start == end)
		return;
	if(end - start == 1)
	{
		merge(arr, start, start, end);
		return;
	}
	int mid = (start + end) / 2;
	sort(arr, start, mid);
	sort(arr, mid, end);
	merge(arr, start, mid, end);
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
	// Create L ← A[p..q] and M ← A[q+1..r]
	//printf("%d\t%d\t%d\n", p, q, r);
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;
	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}
}

// print array
void printArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d  ", array[i]);
	}
	printf("\n");
}

