#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main(void)
{
	myStack *s;
	init(s);printCurrent(*s);
	push(s,10);printCurrent(*s);
	push(s,16);printCurrent(*s);
	
	printf("YES");
	return 0;
}
void init(myStack *s)
{
	s->pTop=NULL;
}
void push(myStack *s,int x)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->num=x;
	if(isEmpty(*s))
	{
		temp->pNext=NULL;
	}
	else
	{
		temp->pNext=(s->pTop);
		s->pTop=temp;
	}
}
int isEmpty(myStack s)
{
	if(s.pTop==NULL)
		return 1;
	return 0;
}
void printCurrent(myStack s)
{
	node *temp=s.pTop;
	printf("\n%d",temp->num);
}
