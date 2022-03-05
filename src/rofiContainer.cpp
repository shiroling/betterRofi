#include "rofiContainer.h"

RofiContainer::RofiContainer() {
	strcpy(this->M_name, "default");
	strcpy(this->M_shell, "/bin/bash");
	strcpy(this->M_base, "rofi");
	strcpy(this->M_optionString, "");
	if (isFileExist("/home/Shiker/.config/rofi/default.rasi"))
	{
		strcpy(this->M_theme, "/home/Shiker/.config/rofi/default.rasi");
	}else{
			strcpy(this->M_theme, "");
	}
}
//print the base command, the used sheel, the options and the theme.
void RofiContainer::printData() {
	printf("Rofi configuration: %s\nRofi command:%s\nExcuted by %s\nOptions: %s\nTheme source:|%s|\n",
			this->M_name, this->M_base, this->M_shell, this->M_optionString, this->M_theme);
}

void RofiContainer::setName(char name[NAME_BUFFER]){
	strncpy(this->M_name, name, NAME_BUFFER);
}

void RofiContainer::setShell(char shell[SHELL_BUFFER]) {
	if (isFileExist(shell))
		strncpy(this->M_shell, shell, SHELL_BUFFER);
} // verify if sell exist

void RofiContainer::setTheme(char theme[THEME_BUFFER]) {
	if (isFileExist(theme))
		strncpy(this->M_theme, theme, THEME_BUFFER);
} // verify if file exist

/*
char* RofiContainer::launch() {

}

// verify if can run
void RofiContainer::setBase(const char base[this->BASE_BUFFER]) {

}
void RofiContainer::setOptionString(char* optionString) {

} //verify conformity of the string.
void generateOptionString(char *options[]){
}

*/

