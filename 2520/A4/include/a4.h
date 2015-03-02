/* Deon Naltchadjian
 * 0832759
 * Nov 24th 2014
 * Assignment 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char * key;
	struct node * left;
	struct node * right;
	int frequency;
	int height;
}node;

node * initialize();
node * insert(char *, node  *);
node * rotateR(node *);
node * rotateL(node *);

char * maxStr(char *, char *);
int max(int, int);
node * find(node *, char *);
node * removeNode(node *, char *);

int checkBalance(node *);
int getHeight(node *);
int countNodes(node *);
int totalHeight(node *, int);
void checkFreq();
void aboveFreq(node *, int);
void inorder(node *);
