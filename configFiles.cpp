#include <iostream>
#include <cstring>
#include <string>

char cfg[25] = "configs/exemple.cfg";

int getBegin(char *str, FILE* fic);	
// function witch find if the given line is the begining of a parameter 
// will return the seek of the begin of the class in case of fail will return 
char *getName(char *str);

int main(int argc, char const *argv[])
{
	FILE *fic = fopen(cfg , "r");
	if (fic == NULL)
		exit(EXIT_FAILURE);

	int i = 0;
	char line[65];
	while (fscanf(fic, "%s\n", line) != EOF)
	{
		int seek;
		if(seek = getBegin(line, fic))
			printf("%s\n", getName(line));
	}
	return 0;
}

int getBegin(char *str, FILE* fic)
{ 
	int length = strlen(str);
	if (str[0] != '$' || str[length-1] != ';')
		return(0);

	int seek = ftell(fic);
	printf("%d:%c\n", seek-length, fgetc(fic));
	
	return (seek-length);
}

char *getName(char *str)
{
	for (int i = 1; i < strlen(str); ++i)	//voulontary 1 to ignore the '$' mark from the config
		{
		if(str[i] != ';')
		{
			str[i-1] = str[i];
		} else {
			str[i-1] = '\0';
			return str;
		}
	}
	return str;
}