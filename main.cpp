#include <iostream>
#include <cstdlib>
#include <string.h>

#include "src/optionNode.h"
#include "src/rofiContainer.h"
int main(int argc, char const *argv[])
{
	int len;
	RofiContainer rofiLul = RofiContainer();
	OptNode optionList = OptNode("PetitZebi", Rtype::link, "www.google.com");
	
	OptNode next1 = OptNode("Nexti", Rtype::command, "ls -al");
	OptNode next2 = OptNode("Nexto", Rtype::command, "ls -la");
	optionList.setNext(&next1);
	optionList.setNext(&next2);

	rofiLul.setOptNode(&optionList);
	rofiLul.printNodeList();

	char *zob;
	zob = optionList.getOptionString();
	printf("optString:\n%s...ACK\n\n", zob);

	zob = rofiLul.getCmdString();
	printf("optString:\n%s...ACK\n", zob);
	return 0;
}