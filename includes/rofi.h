#ifndef ROFI_H
#define ROFI_H


class rofi
{
public:
	int buffer = 32;
	char hint[16];
	char theme[32];

	int text(rofi rf);
	int choice(rofi rf);
	char * getAnswer(char *choice);
	int getLength(char outputFile[20]);
};
#endif