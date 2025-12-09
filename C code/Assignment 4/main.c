#include <stdio.h>
#include <stdlib.h>

char * upper(const char * msg);

char * lower(const char * msg);

int vowels(const char * msg);

int countChar(const char * msg, const char search);

char * substringMatch(const char * msg, const char * submsg);

char * delimit(const char * msg, const char delim);

char * substringDelete(const char * msg, const char * submsg);

int flow(const char * msg);

int main(){
	
	char * upHello = upper("Hello there");
	
	if(upHello){
		printf("%s\n", upHello);
		free(upHello);
	}
	
	
	char * upHey = upper("hey!");
	
	if(upHey){
		printf("%s\n", upHey);
		free(upHey);
	}
	
	char * lowName = lower("MY NAME IS:");
	
	if(lowName){
		printf("%s\n", lowName);
		free(lowName);
	}
	
	char * lowKay = lower("KAYLAN");
	
	if(lowKay){
		printf("%s\n", lowKay);
		free(lowKay);
	}
	
	int comVowels = vowels("Computer science");
	
	if(comVowels > -1){
		printf("Number of vowels: %d\n", comVowels);
	}
	
	int illVowels = vowels("Illustration");
	
	if(illVowels > -1){
		printf("Number of vowels (2nd): %d\n", illVowels);
	}
	
	
	int delChar = countChar("Delimiter", 'i');
	
	if(delChar){
		printf("Number of i's in Delimiter: %d\n", delChar);
	}
	
	int evChar = countChar("Everyday", 'e');
	
	if(evChar){
		printf("Number of e's in Everyday: %d\n", evChar);
	}
	
	char * helMatch = substringMatch("Hello world", "llo");
	
	if(helMatch){
		printf("does llo appear: %s\n", helMatch);
	}
	
	char * plaMatch = substringMatch("Hello world", "planet");
	
	if(plaMatch){
		printf("Does planet appear: %s\n", plaMatch);
	}
	
	char * matchDelim = delimit("Laminate", 'i');
	
	if(matchDelim){
		printf("Matching: %s\n", matchDelim);
		free(matchDelim);
	}
	
	char * noDelim = delimit("Nothingness", 'z');
	
	if(noDelim){
		printf("No match: %s\n", noDelim);
		free(noDelim);
	}
	
	char * yesDel = substringDelete("mango", "go");
	
	if(yesDel){
		printf("deleted: %s\n", yesDel);
		free(yesDel);
	}
	
	char * noDel = substringDelete("Pumpkin", "easy");
	
	if(noDel){
		printf("Not deleted: %s\n", noDel);
		free(noDel);
	}
	
	int yesFlow = flow("Shes singing German");
	
	if(yesFlow > -1){
		if(yesFlow == 1){
			printf("has flow\n");
		}
		else{
			printf("no flow\n");
		}
	}
	
	int noFlow = flow("Hello man");
	
	if(noFlow > -1){
		if(noFlow == 1){
			printf("has flow\n");
		}
		else{
			printf("no flow\n");
		}
	}

	return 0;
}

















