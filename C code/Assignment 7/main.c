#include <stdio.h>
#include <stdlib.h>

int processQuery(char *queryLine, const char *dataFile);

int main(int argc, char** argv){
	if(argc < 3){
		printf("Please put the input file and query file names in the command line, respectively");
		return EXIT_FAILURE;
	}
	
	char * input = argv[1];
	
	
	FILE *query = fopen(argv[2], "r");
	if(!query){
		printf("Error opening query file");
		return EXIT_FAILURE;
	}

	char * line = NULL;
	size_t size = 0;
	
	while(getline(&line, &size, query) != -1){
		int result = processQuery(line, input);
		if(result == 0){
			printf("Sucessfully processed query\n");
		}
		else{
			printf("Something went wrong processing query\n");
			return EXIT_FAILURE;
		}
	}
	
	fclose(query);
	return EXIT_SUCCESS;
}
