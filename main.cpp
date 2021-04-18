#include "includes/main.h"
#include "includes/rofis_constructor.h"

class rofi {
public:
	int buffer = 32;
	char hint[16];
	char theme[32];
	char choice[32];

	int text(rofi rf);
};

int main(int argc, char const *argv[])
{
	rofi test;
	strcpy(test.theme, "textEntry.rasi");
	strcpy(test.hint, "oui");
	test.text(test);

	printf("%s\n", test.choice);
}

int rofi::text(rofi rf)
{
	char outputFile[20];
	strcpy(outputFile, "/tmp/betterRofi.tmp");
	char *command = (char*)malloc(sizeof("bash -c 'rofi -dmenu -i -no-fixed-num-lines -theme $HOME/.config/betterRofi/themes/ -p \"\" > '")
		 						+ sizeof(rf.theme) + sizeof(rf.hint) + sizeof(outputFile));

	if (command == NULL)
		exit(EXIT_FAILURE);

	sprintf(command, "bash -c 'rofi -dmenu -i -no-fixed-num-lines -theme $HOME/.config/betterRofi/themes/%s -p \"%s\" > %s'", rf.theme, rf.hint, outputFile);
	printf("%s\n", command);
	system(command);
	free(command);

	FILE *fic = fopen(outputFile , "r");
	if (fic == NULL)
		exit(EXIT_FAILURE);


	fscanf(fic, "%s/n", rf.choice);
		exit(EXIT_FAILURE);
		printf("%s\n", rf.choice);
	return 0;
}