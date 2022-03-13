#ifndef ROFICONTAIN_H_
#define ROFICONTAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>

#define R_NAME_BUFFER 64
#define	R_BASE_BUFFER 128
#define	R_SHELL_BUFFER 16
#define R_THEME_BUFFER 256

#include "popen3.h"
#include "fileUtils.h"
#include "optionNode.h"


class RofiContainer
{
public:	

	//Constructor
	RofiContainer();


	void printData(); //print the base command, the used sheel, the options and the theme.
	void printNodeList();

	void setName(char* name);
	void setBase(char* base);	// verify if can run
	void setShell(char* shell); // verify if sell exist
	void setTheme(char* theme);	// verify if file exist

	void setOptNode(OptNode *node);
	//void setOptionString(char* optionString); //verify conformity of the string.

	char* getCmdString();	// Nedeed for the launch
	char* launch(); 			// fork the rofi process and return the rofi output.

private:
	char M_name[R_NAME_BUFFER];
	char M_base[R_BASE_BUFFER];
	char M_shell[R_SHELL_BUFFER];
	OptNode *M_options;
	char M_theme[R_THEME_BUFFER];
};

#endif