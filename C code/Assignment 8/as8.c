#include <stdio.h>
#include <stdlib.h>


char * adjacentLetters(char * look){
	if(!look || !*(look + 1)){
		return NULL;
	}
	
	char curr = *look;
	char next = *(look + 1);
	
	if(curr >= 'A' && curr <= 'Z'){
		curr = curr - 'A' + 'a';
	}
	
	if(next >= 'A' && next <= 'Z'){
		next = next - 'A' + 'a';
	}
	
	int isLet1 = 0;
	int isLet2 = 0;
	
	if(curr >= 'a' && curr <= 'z'){
		isLet1 = 1;
	}
	
	if(next >= 'a' && next <= 'z'){
		isLet2 = 1;
	}
	
	if(isLet1 == 1 && isLet2 == 1 && (next == curr+1 || curr == next-1)){
		return look;
	}
	
	return adjacentLetters(look+1);
	
}



void compress2DRec(int ** arr, int row, int totalRows, int *result){
	
	if(row == totalRows){
		return;
	}
	
	int a = *(*(arr+row) +0);
	int b = *(*(arr+row) +1);
	int c = *(*(arr+row) +2);
	
	int min = a;
	
	if(min > b){
		min = b;
	}
	
	if(min > c){
		min = c;
	}
	
	int max = a;
	
	if(b > max){
		max = b;
	}
	
	if(c > max){
		max = c;
	}
	
	int remain;
	if(a != min && a != max){
		remain = a;
	}
	
	else if( b != min && b != max){
		remain = b;
	}
	
	else{
		remain = c;
	}
	
	
	*(result + row) = (max * min) - remain;
	
	compress2DRec(arr, row+1, totalRows, result);
}


int *compress2D(int **arr, int rows){
	int *result = (int *)malloc(rows * sizeof(int));
	
	if(result == NULL){
		return NULL;
	}
	
	compress2DRec(arr, 0, rows, result);
	
	return result;
}


void insertionSortRec(int *arr, int size, int sortedCount, int mode){
	
	if(sortedCount >= size){
		return;
	}
	
	int key = *(arr + sortedCount);
	
	int *ptr = arr + sortedCount - 1;
	
	if(mode == 0){
		while(ptr >= arr && *ptr > key){
			*(ptr+1) = *ptr;
			ptr--;
		}
	}
	else{
		while(ptr >= arr && *ptr < key){
			*(ptr +1) = *ptr;
			ptr--;
		}
	}
	
	*(ptr+1) = key;
	
	insertionSortRec(arr, size, sortedCount +1, mode);
}

















































