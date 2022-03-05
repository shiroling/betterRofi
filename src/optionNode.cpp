#include "optionNode.h"

OptNode::OptNode(const char name[NAME_BUFFER], Rtype type, const char argument[ARG_BUFFER]) {
	strncpy(this->M_name, name, NAME_BUFFER);
	this->M_type = type;
	strncpy(this->M_argument, argument, ARG_BUFFER);
	this->M_next = NULL;
	this->M_child = NULL;
}

void OptNode::setNext(OptNode *next) {
	this->M_next = next;
}

void OptNode::setChild(OptNode *child) {
	this->M_child = child;
}

bool OptNode::isChild() {
	return (this->M_child != NULL);
}

bool OptNode::isNext() {
	return (this->M_next != NULL);
}

OptNode *OptNode::getNext() {
	if (!this->isNext())
	{
		printf("No next to give !\n");
		exit(EXIT_FAILURE);
	}
	return this->M_next;
}

OptNode *OptNode::getChild() {
	if (!this->isChild())
	{
		printf("No child to give !\n");
		exit(EXIT_FAILURE);
	}
	return this->M_child;
}

void OptNode::printNode() {
	printf("Node:%s\nIs type:%d\nWith arg:%s\n", 
		this->M_name, this->M_type, this->M_argument);
}
void OptNode::printChild() {	//Make a printNode(); from the child if there is one | print "No child"
	if (this->M_child != NULL)
	{
		this->M_child->printNode();
	}else{
		printf("Concurent have no Child node\n");
	}
}
void OptNode::printNext() {	//Make a printNode(); from the next if there is one | print "No next"
	if (this->M_next != NULL)
	{
		this->M_next->printNode();
	}else{
		printf("Concurent have no next node\n");
	}
}

void OptNode::printList() {
	this->printNode();
	printf("----------------------\n");
	if (this->M_next == NULL)
	{
		printf("no next\n");
		return;
	}
	this->M_next->printList();

}

/*
void setName(char* name);
void setType(char* base); 
void setArg(char* argument);
*/



