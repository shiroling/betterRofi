#include "includes/main.h"
#include "includes/rofi.h"

int main(int argc, char const *argv[])
{
	rofi test;
	strcpy(test.theme, "textEntry.rasi");
	strcpy(test.hint, "oui");

	int length = test.text(test);

	char *answer = (char*)malloc( sizeof(char) * length);
	test.getAnswer(answer);
}