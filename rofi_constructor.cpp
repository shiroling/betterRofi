#include "includes/main.h"
#include "includes/rofis_constructor.h"


class rofi {
	int buffer;
	char *choice;

public:
	const char *text(rofi rf, char* hint);
};


const char* rofi::text(rofi rf, char* hint)
{
	char themeFile[16], outputFile[20];
	strcpy(hint, "asy !");
	strcpy(themeFile, "textEntry.rasi");
	strcpy(outputFile, "/tmp/betterRofi.tmp");

	char *command = (char*)malloc(sizeof("bash -c 'rofi -dmenu -i -no-fixed-num-lines -theme $HOME/.config/betterRofi/themes/ -p \"\" > '")
		 						+ sizeof(themeFile) + sizeof(hint) + sizeof(outputFile));

	if (command == NULL)
		exit(EXIT_FAILURE);

	sprintf(command, "bash -c 'rofi -dmenu -i -no-fixed-num-lines -theme $HOME/.config/betterRofi/themes/%s -p \"%s\" > %s'", themeFile, hint, outputFile);
	system(command);
	free(command);

	FILE *fic = fopen(outputFile , "r");
	if (fic == NULL)
		exit(EXIT_FAILURE);


	char *tmp;
	if (fgets(tmp, buffer, fic) != NULL)
		exit(EXIT_FAILURE);
    
    rf.choice = (char*)malloc(sizeof(tmp));
    strcpy(rf.choice, tmp);
	return 0;
}