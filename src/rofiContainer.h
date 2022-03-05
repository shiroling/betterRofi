#ifndef ROFICONTAIN_H_
#define ROFICONTAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>

#define NAME_BUFFER 64
#define	BASE_BUFFER 128
#define	SHELL_BUFFER 16
#define THEME_BUFFER 256


#include "fileUtils.h"

class RofiContainer
{
public:	

	//Constructor
	RofiContainer();


	//char* launch(); //function that fotr the rofi process and return the rofi output.
	void printData(); //print the base command, the used sheel, the options and the theme.

	void setName(char* name);
	void setBase(char* base);   // verify if can run
	void setShell(char* shell); // verify if sell exist
	void setTheme(char* theme);  // verify if file exist

	//void setOptionString(char* optionString); //verify conformity of the string.
	//void generateOptionString(char *options[]); // generate a conform string for the rofi options

private:
	char M_name[NAME_BUFFER];
	char M_base[BASE_BUFFER];
	char M_shell[SHELL_BUFFER];
	char M_optionString[16];
	char M_theme[THEME_BUFFER];
};

#endif