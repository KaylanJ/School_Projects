#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * trim(char *str){
	while(*str == ' ' || *str == '\t'){
		str++;
	}
	char * end = str + strlen(str)-1;
	while(end > str && (*end == ' ' || *end == '\t' || *end == '\n')){
		*end = '\0';
		end--;
	}
	return str;
}

int regionMatch(char *regionList, char *rowRegion){
	char temp[256];
	strcpy(temp, regionList);
	
	
	char *token = strtok(temp, "$");
	while(token != NULL){
		if(strcmp(token, "Combined") == 0){
			if(strstr(rowRegion, "Combined") != NULL){
				return 1;
			}
		}
		if(strcmp(trim(token), trim(rowRegion)) == 0){
			return 1;
		}
		token = strtok(NULL, "$");
	}
	return 0;
}

int ageMatch(char *ageList, char *rowAge){
	char temp[128];
	
	strcpy(temp, ageList);
	
	char * token = strtok(temp, " ");
	while(token != NULL){
		if(strcmp(token, rowAge) == 0){
			return 1;
		}
		token = strtok(NULL, " ");
	}
	return 0;
	
}



int charMatch(char *charList, char *rowChar){
	char temp[128];
	
	strcpy(temp, charList);
	
	char *token = strtok(temp, " ");
	while(token != NULL){
		if(strcmp(token, rowChar) == 0){
			return 1;
		}
		token = strtok(NULL, " ");
	}
	return 0;
}
	
int conditionCheck(int rowVal, char op, int val){
	switch(op){
		case '=':
			return (rowVal == val);
		case '>':
			return (rowVal > val);
		case '<':
			return (rowVal < val);
		default:
			return 0;
		
	}
}	


int processQuery(char *queryLine, const char *dataFile){
	
	char delim = ',';
	
	char *outputfile = strtok(queryLine, &delim);
	char *regionList = strtok(NULL, &delim);
	char *ageList = strtok(NULL, &delim);
	char *charList = strtok(NULL, &delim); 
	char *conditionstr = strtok(NULL, &delim);
	
	if(!outputfile || !regionList || !ageList || !charList || !conditionstr){
		printf("Invalid query format.\n");
		return -1;
	}
	
	
	char op;
	int value;
	int n = 0;
	
	if(strcmp(conditionstr, "N/A") != 0 && strlen(conditionstr) > 0){
		n = sscanf(conditionstr, "%c%d", &op, &value);
		
		if(n!= 2){
			strcpy(conditionstr, "N/A");
		}
	}
	
	if(strlen(regionList) == 3){
		strcpy(regionList, "N/A");
	}
	
	FILE *in = fopen(dataFile, "r");
	
	if(!in){
		printf("Error opening data file");
		return -1;
	}
	
	FILE *out = fopen(outputfile, "w");
	
	if(!out){
		printf("Error opening output file");
		return -1;
	}
	
	
	char *line = NULL;
	
	size_t size = 0;
	
	char linecopy[1024];
	
	getline(&line, &size, in);
	
	while(getline(&line, &size, in) != -1){
		
		strcpy(linecopy, line);
		
		//char ** data = malloc(sizeof(char*) *12);
		
		char *data[12];
		int count = 0;
		
		line[strcspn(line, "\n")] = '\0';
		char * token = strtok(line, &delim);
		
		while(token != NULL){
			data[count] = token;
			count++;
			token = strtok(NULL, &delim);
		}
		
		
		if(( strcmp(regionList, "N/A") == 0 || regionMatch(regionList, data[4]) == 1) && (strcmp(ageList, "N/A") == 0 || ageMatch(ageList, data[6]) == 1) && (strcmp(charList, "N/A") == 0 || charMatch(charList, data[8]) == 1) && (strcmp(conditionstr, "N/A") == 0 || conditionCheck(atoi(data[10]), op, value) == 1)){
			fputs(linecopy, out);
		}
		//free(data);
		
		
	}
	
	free(line);
	fclose(out);
	fclose(in);
	return 0; //sucess! nonzero is failure or error smt like that
}



