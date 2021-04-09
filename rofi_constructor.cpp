#include "includes/main.h"


class rofi {

	const char *text(char* hint, int buffer)
	{
		char choice[buffer], themeFile[16], outputFile[20];
		strcpy(hint, "asy !");
		strcpy(themeFile, "textEntry.rasi");
		strcpy(outputFile, "/tmp/betterRofi.tmp");

		char *command = (char*)malloc(sizeof("bash -c 'rofi -dmenu -i -no-fixed-num-lines -theme $HOME/.config/betterRofi/themes/ -p \"\" > '") + sizeof(themeFile) + sizeof(hint) + sizeof(outputFile));
		if (command == NULL)
			exit(EXIT_FAILURE);

		sprintf(command, "bash -c 'rofi -dmenu -i -no-fixed-num-lines -theme $HOME/.config/betterRofi/themes/%s -p \"%s\" > %s'", themeFile, hint, outputFile);
		system(command);
		free(command);

		FILE *fic = fopen(outputFile , "r");
		if (fic == NULL)
			exit(EXIT_FAILURE);



		if (fgets(choice, buffer, fic) != NULL)
			exit(EXIT_FAILURE);
	    	
	    printf("the choice is of .text is: %s", choice);
		return (choice);
	}
};