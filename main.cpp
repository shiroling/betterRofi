#include "includes/main.h"

int main(int argc, char const *argv[])
{
	char hint[16], themeFile[16], outputFile[20];
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

		char choice[32];
	if (fgets(choice, 32, fic) != NULL)
    	printf("the choice is: %s", choice);
    sleep(5);
	system("rm /tmp/betterRofi.tmp");

	exit(EXIT_FAILURE);
}