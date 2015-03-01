 /*********************************************
 * Deon Naltchadjian
 * 0832759
 * CIS*2750 A1
 * FINAL Due Jan 23 2015
 *********************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*Basic linked list structure*/
typedef struct List{
	
	char * val;
	struct List * next;
	
}List;

/*Creates an empty list
 * Return List on success, NULL on fail*/
struct List * List_create();

/*Destroy the list, freeing all nodes
 * Return 1 on success, 0 on fail*/
int List_destroy(struct List * l);

/*Add the string into the next available element
 * Return 1 on success, 0 on fail*/
int List_addNext(struct List * l, char * info);

/*used for testing
 * Return 1 on success, 0 on fail*/
int List_printList(struct List * l);
