#include <stdio.h>
#include <stdlib.h>

int strLen(char * s){
	int len = 0;
	while(s[len] != '\0'){
		len++;
	}
	return len;
}

char * upper(char * msg){
	
	int size = strLen(msg);
	
	char * result = malloc(size+1);
	
	if(result == NULL){
		return NULL;
	}
	
	for(int i = 0; i < size; i++){
		if(msg[i] >= 'a' && msg[i] <= 'z'){
			result[i] = msg[i] - 32;
		}
		else{
			result[i] = msg[i];
		}
	}
	result[size] = '\0';
	
	return result;
	
	
}

char * lower(char * msg){
	int size = strLen(msg);
	
	char * result = malloc(size+1);
	
	if(result == NULL){
		return NULL;
	}
	
	for(int i =0; i < size; i++){
		if(msg[i] >= 'A' && msg[i] <= 'Z'){
			result[i] = msg[i] + 32;
		}
		else{
			result[i] = msg[i];
		}
	}

	result[size] = '\0';
	
	return result;
}


int vowels(char * msg){
	
	int vowels = 0;

	char * allOneCase = lower(msg);
	
	if(allOneCase == NULL){
		return -1;
	}
	
	char * ptr = allOneCase;
	
	while(*ptr != '\0'){
		if(*ptr == 'y' || *ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u'){
			vowels++;
		}
		ptr++;
	}
	free(allOneCase);
	
	return vowels;
}

int countChar(char * msg, char search){
	int size = strLen(msg);
	
	int count = 0;
	
	for(int i = 0; i < size; i++){
		if(msg[i] == search){
			count++;
		}
	}
	return count;
}

char * substringMatch(char * msg, char * submsg){
	
	char * ptr = msg;
	
	int flag = 0; //false
	
	while(*ptr != '\0' && flag == 0){
		if(*ptr == *submsg){
			char * cmpr1 = ptr;
			char * cmpr2 = submsg;
			while(*cmpr1 == *cmpr2){
				cmpr1++;
				cmpr2++;
				if(*cmpr2 == '\0'){
					flag = 1;
					break;
				}
			}
		}
		ptr++;
	}
	
	
	if(flag == 1){
		return ptr-1;
	}else{
		return NULL;
	}
	
}

char * delimit(char * msg, char delim){
	int size = strLen(msg);
	
	char * copy = malloc(size + 1);
	
	if(copy == NULL){
		return NULL;
	}
	int i;
	for(i = 0; i <size; i++){
		if(msg[i] == '\0' || msg[i] == delim){
			break;
		}
		else{
			copy[i] = msg[i];
		}
	}
	copy[i] = '\0';
	
	return copy;
}

char * substringDelete(char * msg, char * submsg){
	int size = strLen(msg);
	
	int subSize = strLen(submsg);
	
	if(subSize == 0){
	
		char * copy = malloc(size+1);
		if(copy == NULL){
			return NULL;
		}
		for(int i = 0; i <= size; i++){
			copy[i] = msg[i];
		}
		return copy;
	}
	
	char * result = malloc(size+1);
	
	if(result == NULL){
		return NULL;
	}
	
	int i=0; 
	int j=0;
	
	while(i<size){
		
		int match = 1;
		for(int k = 0; k<subSize; k++){
			if(msg[i+k] != submsg[k] || msg[i+k] == '\0'){
				match = 0;
				break;
			}
		}
		
		if(match == 1){
			i = i+subSize;
		}
		else{
			result[j++] = msg[i++];
		}
		
		
	}
	result[j] = '\0';
	return result;
}

int flow(char * msg){
	
	int size = strLen(msg);
	
	char * lowercase = lower(msg);
	
	
	
	if(lowercase == NULL){
		return -1;
	}
	
	int flow = 1; //assume true
	
	for(int i = 0; i<size; i++){
		if(lowercase[i] == ' ' && i > 0 && lowercase[i+1] != '\0'){
			if(lowercase[i-1] != lowercase[i+1]){
				flow = 0; //no flow
			}
		}
		
	}
	free(lowercase);
	
	return flow;
	
	
}































