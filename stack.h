
#ifndef STACK_H
#define STACK_H

typedef struct node
{
	int num;
	struct node *pNext;
}node;
typedef struct 
{
	node *pTop;
}myStack;


void init(myStack *s);

void push(myStack *s,int x);
int isEmpty(myStack s);
void printCurrent(myStack s);
#endif
