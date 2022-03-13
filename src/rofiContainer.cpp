#include "rofiContainer.h"

RofiContainer::RofiContainer() {
	strcpy(this->M_name, "default");
	strcpy(this->M_shell, "/bin/bash");
	strcpy(this->M_base, "rofi");
	if (isFileExist("/home/Shiker/.config/rofi/default.rasi"))
	{
		strcpy(this->M_theme, "/home/Shiker/.config/rofi/default.rasi");
	}else{
		strcpy(this->M_theme, "");
	}
}
//print the base command, the used sheel, the options and the theme.
void RofiContainer::printData() {
	printf("Rofi configuration: %s\nRofi command:%s\nExcuted by %s\nTheme source:|%s|\n",
			this->M_name, this->M_base, this->M_shell, this->M_theme);
}

void RofiContainer::printNodeList() {
	this->M_options->printList();
}

void RofiContainer::setName(char name[R_NAME_BUFFER]){
	strncpy(this->M_name, name, R_NAME_BUFFER);
}

void RofiContainer::setShell(char shell[R_SHELL_BUFFER]) {
	if (isFileExist(shell))
		strncpy(this->M_shell, shell, R_SHELL_BUFFER);
} // verify if sell exist

void RofiContainer::setTheme(char theme[R_THEME_BUFFER]) {
	if (isFileExist(theme))
		strncpy(this->M_theme, theme, R_THEME_BUFFER);
} // verify if file exist

void RofiContainer::setOptNode(OptNode *node) {
	if (node != NULL)
		this->M_options = node;
}



char* RofiContainer::getCmdString() {
	char *output = 	this->M_options->getOptionString();
	return output;
}	









char* RofiContainer::launch() {
	if (this->M_options == NULL)
	{
		printf("Missing option list !\n");
		exit(EXIT_FAILURE);
	}
	
	char *temp;
	strcpy(temp, "oui");
	return temp;
}

/*
// verify if can run
void RofiContainer::setBase(const char base[this->BASE_BUFFER]) {

}
void RofiContainer::setOptionString(char* optionString) {

} //verify conformity of the string.
void generateOptionString(char *options[]){
}

*/

