#ifndef OPT_NODE_H_
#define OPT_NODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define NAME_BUFFER 64
#define ARG_BUFFER 1024
enum class Rtype {
	null = -1,
	rofi = 0, 
	link = 1,
	command = 2
};

class OptNode
{
public:
	//Constructor
	OptNode();
	OptNode(const char name[NAME_BUFFER], Rtype type, const char argument[ARG_BUFFER]);
	void setNext(OptNode *next);
	void setChild(OptNode *child);

	OptNode *getNext();
	OptNode *getChild();

	bool isChild();
	bool isNext();

	void printList();
	void printNode();	//print the base command, the used sheel, the options and the theme.
	void printChild();	//Make a printNode(); from the child if there is one | print "No child"
	void printNext();	//Make a printNode(); from the next if there is one | print "No next"

	int*  getOptStringLen(int* optSringLen); // return an int ptr to the length of the option string
	char* getOptionString();


private:
	OptNode *M_next;
	OptNode *M_child;
	char  M_name[NAME_BUFFER];
	Rtype M_type;
	char  M_argument[ARG_BUFFER];	// this is what will be executed, It will be a web link if the node is Rtype = link
														// or a unix command if Rtype = command
														// or a NULL if Rtype = rofi
};

#endif