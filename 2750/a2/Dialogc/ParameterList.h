 /*********************************************
 * Deon Naltchadjian
 * 0832759
 * CIS*2750 A1
 * FINAL Due Jan 23 2015
 *********************************************/
 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "List.h"

/*ParameterList object
 * holds a string with the value of a single element in the list of parameters
 * a pointer to the next list element
 */
typedef struct ParameterList{
	
	struct List * list;
	struct List * front;
	int size;
	
}ParameterList;

/*Creates a new parameter list object
  PRE: none
  POST: Returns a new parameter list object initialized to be empty 
  * on success, NULL otherwise (memory allocation failure)
  */
struct ParameterList * PL_create();
int PL_destroy(struct ParameterList * pl);
/*Obtain the next item in a parameter list
  PRE: n/a
  POST: Returns the next item in parameter list l, NULL if there are no items remaining in the list
  */
char * PL_next(struct ParameterList * l);
