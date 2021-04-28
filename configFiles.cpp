#include "includes/main.h"
#include "includes/configFiles.h"
#include "includes/node.h"

char cfgFile[25] = "configs/exemple.cfg";

int main(int argc, char const *argv[])
{
	FILE *fic = fopen(cfgFile , "r");
	if (fic == NULL)
		exit(EXIT_FAILURE);

	int seek = findByName(fic, "choix4");
	node testNode;
	testNode = isCorrect(seek, fic, "choix4");
	printf("seek cfg:%d / seek choices:%d\n", testNode.seekCfg, testNode.seekChoices);
	return 0;
}

int findByName(FILE *fic, const char *name)
{
	char line[128];
	while (fscanf(fic, "%s\n", line) != EOF)
	{
		if (line[0] == '$')
		{
			getName(line);
			if (strcmp(name,line) == 0)
			{
				return ftell(fic);
			}
		}
	}
	printf("Not found\n");
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

node isCorrect(int seek, FILE *fic, const char name[32])
{
	char line[128];
	int i = 0, seekCfg = 0, seekChoices = 0;
	bool hint = 0, theme = 0;
	while (fscanf(fic, "%s\n", line) != EOF)
	{	
		if (seekCfg == 0)
			if (strcmp(line, "cfg") != 0)
			{
				seekCfg = ftell(fic) - 3; // le moins 3 c un correctif à la con cherchez pas

				while(line[0] != '}') {
					fscanf(fic, "%s\n", line);
					if (strcmp(line, "hint:"))
					{
						hint = 1;
					}

					if (strcmp(line, "theme:"))
					{
						theme = 1;
					}
				}
				if(!hint && !theme)
				{
					printf("missing hint or theme in config\n");
					exit(EXIT_FAILURE);
				}
			printf("passed cfg: %ld\n", ftell(fic));
			}
		if (seekChoices == 0)
			if (strcmp(line, "choices") == 0)
			{
				printf("%s. %d", line, (strcmp(line, "choices") == 0));
				seekChoices = ftell(fic);
				while(line[0] != '}') {
					fscanf(fic, "%s\n", line);
					printf("%s: %c.%c\n", line, line[0], line[strlen(line)-1]);
					if (line[0] == '"' && line[strlen(line)-1] == '"')
						i++;
					if (line[0] == '<' && line[strlen(line)-1] == '>')
						i++;
				}
				if(i<1)
				{
					printf("not enouth choices\n");
					exit(EXIT_FAILURE);
				}
			}
	}

	if (seekCfg == 0 || seekChoices == 0) {
		printf("missing part in %s at %d\n", name, seek);
		exit(EXIT_FAILURE);
	}

	node n;
	n.seekCfg = seekCfg;
	n.seekChoices = seekChoices;
	return n;
}