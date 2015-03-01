 /*********************************************
 * Deon Naltchadjian
 * 0832759
 * CIS*2750 A1
 * FINAL Due Jan 23 2015
 *********************************************/

#include "ParameterList.h" 
 
/*Creates a new parameter list object/element
  PRE: none
  POST: Returns a new parameter list object initialized to be empty 
  * on success, NULL otherwise (memory allocation failure)
  */
struct ParameterList * PL_create(){
	
	struct ParameterList * pl = malloc(sizeof(struct ParameterList));
	
	if(pl == NULL){
		fprintf(stderr, "Memory allocation failure on PL_create\n");
		return NULL;
	}
	
	pl->size = 0;
	
	return pl;
	
}

/*Destroys a parameter list object
  PRE: n/a
  POST: all memory associated with parameter list pl is freed along with any following list elements;
  * returns 1 on success, 0 otherwise
  */
int PL_destroy(struct ParameterList * pl){
	
	if((List_destroy(pl->list)) == 0){
		fprintf(stderr, "Error destroying linked list\n");
		return 1;
	}
	
	free(pl);
	return 1;
	
}

/*Obtain the next item in a parameter list
  PRE: n/a
  POST: Returns the next item in parameter list l, NULL if there are no items remaining in the list
  */
char * PL_next(struct ParameterList * pl){ /*ONLY GOTTA GO THROUGH ONCE DONT WORRY ABOUT LOSING THE POINTER*/
	
	struct List * temp;
	
	if(pl->list == NULL){
		return NULL;
	}
	
	temp = pl->list;
	pl->list = pl->list->next;
	return temp->val;
}

