/*
	tree.c 
	include some function for syntax tree and stack

	tree
	use Node struct, with max children CH_MAX
	include: initT, create, link, printT

	stack
	use Stack struct, with max size STACK_MAX
	include: initS, top, pop, push

	by:Jinyi
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_MAX 1000
#define CH_MAX 10
typedef struct Node{
	char* name;
	int ch;
	struct Node *c[CH_MAX];
}Node, *PNode;

typedef struct Stack{
	int size;
	int t;
	PNode data[STACK_MAX];
}Stack, *PStack;

//tree
void initT(PNode n, char *elem)
{
	n->name = elem;
	n->ch = 0;
	int i;
	for(i=0; i<CH_MAX; i++) n->c[i] = NULL;
}

//create the node with char
PNode create(char *par)
{
	PNode n = (PNode)malloc(sizeof(Node));
	initT(n, par);
	return n;
}

//link children node to the parent node, after the exiting children
int link(PNode pare, PNode child)
{
	if (pare->ch < CH_MAX) {
		int i = pare->ch;
		pare->ch = pare->ch+1;
		pare->c[i] = child;
		return 1;
	}	
	else return 0;
}

//print the whold tree, flag for error in .y
void printT(PNode root, int level, FILE *out, int flag)
{
	if (flag==1) {
		fprintf(out, "Error\n");
		return;
	}
	int i;
	for(i=0; i<level; i++) {
		printf("\t");
		fprintf(out, "\t");
	}
	printf("%s\n", root->name);
	fprintf(out, "%s\n", root->name);
	for(i=0; i<root->ch; i++) {
		printT(root->c[i], level+1, out, flag);
	}
}

//stack
void initS(PStack n)
{
	n->size=0;
	n->t= -1;
}

PNode top(PStack a)
{
	if (a->size==0){
		printf("STACK IS EMPTY\n");
		exit(-1);
	}
	return a->data[a->t];		
}
PNode pop(PStack a)
{
	if (a->size==0){
		printf("STACK IS EMPTY\n");
		exit(-1);
	}
	a->size--;
	return a->data[a->t--];
}

void push(PStack a, PNode tdata)
{
	if(a->size == STACK_MAX){
		printf("STACK IS FULL\n");
		exit(1);
	}
	a->size++;
	a->data[++(a->t)]=tdata;
}



