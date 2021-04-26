#include "includes/main.h"
#include "includes/rofi.h"

int rofi::text(rofi rf)
{
	char outputFile[20] = "/tmp/betterRofi.tmp";
	char *command = (char*) malloc( sizeof("bash -c 'rofi -dmenu -i -no-fixed-num-lines -theme $HOME/.config/betterRofi/themes/ -p \": \" > '")
		 						+ sizeof(rf.theme) + sizeof(rf.hint) + sizeof(outputFile) );
	if (command == NULL)
		exit(EXIT_FAILURE);

	sprintf(command, "bash -c 'rofi -dmenu -i -no-fixed-num-lines -theme %s -p \"%s: \" > %s'",
			rf.theme, rf.hint, outputFile);

	system(command);
	free(command);

	return getLength(outputFile);
}

int rofi::choice(char cfg[25], char outputFile[20])
{
	// sprintf("bash -c \"echo -e \"%s\" | rofi -theme ~/.config/betterRofi/themes/%s -p %s -dmenu -selected-row 1 > %s"
	//	,options, theme, hint, file);
	return 0;
}

int rofi::getLength(char outputFile[20])
{
	FILE *fic = fopen(outputFile , "r");
	if (fic == NULL)
		exit(EXIT_FAILURE);

	int i = 0;
	while(fgetc(fic) != '\n') 
		i++;

	return i;
}

char * rofi::getAnswer(char *choice)
{
	char outputFile[20];
	strcpy(outputFile, "/tmp/betterRofi.tmp");

	FILE *fic = fopen(outputFile , "r");
	if (fic == NULL)
		exit(EXIT_FAILURE);

	fscanf(fic, "%s\n", choice);
	fclose(fic);
	
	return(choice);
}