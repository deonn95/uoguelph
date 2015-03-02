/* Deon Naltchadjian
 * 0832759
 * Oct 15 2014
 * Assignment 2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

typedef struct{
	
	int array[MAX];
	int top;
	
}stack;

void newStack(stack *);
int pop(stack *);
void push(stack *, int);
int doMath(char, int, int);
