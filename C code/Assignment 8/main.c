#include <stdio.h>
#include <stdlib.h>

char * adjacentLetters(char * look);

int *compress2D(int **arr, int rows);

void insertionSortRec(int *arr, int size, int sortedCount, int mode);



int main(int argsc, char ** argsv){
	char test1[] = "akMjNoE";
	char test2[] = "zZet";
	
	char *res1;
	
	res1 = adjacentLetters(test1);
	
	if(res1 != NULL){
		printf("Found at: %c%c\n", *res1, *(res1+1));
	}
	else{
		printf("None found in \"%s\"\n", test1);
	}
	
	res1 = adjacentLetters(test2);
	
	if(res1 != NULL){
		printf("Found at: %c%c\n", *res1, *(res1+1));
	}
	else{
		printf("None found in \"%s\"\n", test2);
	}
	
	int data[2][3] = {{5,8,11}, {4,1,12}};
	
	int *arr[2];
	arr[0] = data[0];
	arr[1] = data[1];
	
	int *res2 = compress2D(arr, 2);
	
	if(res2 == NULL){
		printf("Problem with memory allocation\n");
		return EXIT_FAILURE;
	}
	
	for(int i = 0; i < 2; i++){
		printf("%d ", *(res2+i));
	}
	
	printf("\n");
	
	free(res2);
	
	
	int data2[] = {5,2,8,1,3};
	
	int size2 = 5;
	
	printf("Ascending:\n");
	insertionSortRec(data2, size2, 1, 0);
	for(int i = 0; i < size2; i++){
		printf("%d ", *(data2+i));
	}
	
	printf("\n");
	
	int data3[] = {5,2,8,1,3};
	
	int size3 = 5;
	
	printf("Descending:\n");
	
	insertionSortRec(data3, size3, 1, 1);
	
	for(int i = 0; i < size3; i++){
		printf("%d ", *(data3 + i));
	}
	
	printf("\n");
	
	return EXIT_SUCCESS;
	
}























