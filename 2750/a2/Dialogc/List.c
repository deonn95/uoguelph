 /*********************************************
 * Deon Naltchadjian
 * 0832759
 * CIS*2750 A1
 * FINAL Due Jan 23 2015
 *********************************************/

#include "List.h"

/*Creates a new list object/element
  PRE: none
  POST: Returns a new list object initialized to with info as string 
  * on success, NULL otherwise (memory allocation failure)
  */
struct List * List_create(char * info){
	
	struct List * l = malloc(sizeof(struct List));
	l->val = malloc(sizeof(char) * strlen(info) + 1);
	
	if(l == NULL || l->val == NULL){
		fprintf(stderr, "Memory allocation failure on List_create\n");
		return NULL;
	}
	
	strcpy(l->val, info);
	return l;
}

/*Destroys a list object
  PRE: n/a
  POST: all memory associated with list l is freed along with any following list elements;
  * returns 1 on success, 0 otherwise
  */
int List_destroy(struct List * l){
	
	struct List * temp;
	
	if(l == NULL){
		return 1;
	}
	
	do{
		temp = l->next;
		free(l);
		l = temp;
	}while(l->next != NULL);
	
	return 1;
}

/*Adds the information to the next list element
 * PRE: n/a
 * POST: info is added to next available list slot
 * return 1 on success, 0 otherwise
 */
int List_addNext(struct List * l, char * info){
	
	if(l == NULL){
		l = List_create(info);
		if(l == NULL){
			return 0;
		}
		return 1;
	}
	
	struct List * new;
	new = List_create(info);
	
	if(new == NULL){
		return 0;
	}
	
	while(l->next != NULL){
		l = l->next;
	}
	l->next = new;
	new->next = NULL;
	
	return 1;
	
}


/*TESTING PRINT FUNCTION*/
int List_printList(struct List * l){
	
	if(l == NULL){
		return 0;
	}
	
	while(l->next != NULL){
		fprintf(stdout, "%s\n", l->val);
		l = l->next;
	}
	fprintf(stdout, "%s\n", l->val);
	
	return 1;
	
}

