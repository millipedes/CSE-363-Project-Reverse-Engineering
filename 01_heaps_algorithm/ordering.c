#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heaps(int *unused, int length, int time);
void swap(int *a, int *b);
void printarr(int *arr, int length);
int fact(int x);

int main(int argc, char **argv) {
	int val = 7;
	if(argc == 2)
		val = atoi(argv[1]);
	int *arr = calloc(sizeof(int), val);
	for(int i = 1; i <= val; i++)
		arr[i-1] = i;
	int end = fact(val);
	for(int i = 0; i < end; i++) {
		heaps(arr, val, i);
		printf("%d\t|", i);
		printarr(arr, val);
		if(i % 6 == 5)
			printf("\n");
		if(i % 24 == 23)
			printf("\n\n");
	}
	free(arr);		
}

void heaps(int *array, int length, int time) {
	if(length < 2 || time == 0)
		return;	
	if(length % 2 == 1) {
		int doink = fact(length - 1);
		if(time > doink)
			heaps(array, length, time % doink);
		if(time % doink == 0)
			swap(&array[0], &array[length - 1]);
		if(time < doink)
			heaps(array, length - 1, time);
	}
	if(length % 2 == 0) {
		int doink = fact(length - 1);
		int changer = (time - 1) / doink;
		if(time > doink)
			heaps(array, length, time % doink);
		if(time % doink == 0)
			swap(&array[changer],&array[length-1]);
		if(time < doink)
			heaps(array, length - 1, time);
	}
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printarr(int *arr, int length) {
  for(int i = 0; i < length; i++)
    printf("%d,", arr[i]);
  printf("\n");
}

int fact(int x) {
  return x < 1 ? 1 : x * fact(x - 1);
}
