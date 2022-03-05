#include <iostream>
#include <cstdlib>
#include <string.h>

#include "src/optionNode.h"

int main(int argc, char const *argv[])
{
	OptNode optionList = OptNode("PetitZebi", Rtype::link, "www.google.com");
	OptNode child = OptNode("Child", Rtype::command, "ls -al");
	optionList.setChild(&child);
	if (optionList.isChild())
	{
		OptNode *ptr = optionList.getChild();
		ptr->printNode();		
	}
	return 0;
}