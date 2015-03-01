 /*********************************************
 * Deon Naltchadjian
 * 0832759
 * CIS*2750 A1
 * FINAL Due Jan 23 2015
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Boolean.h"
#include "ParameterList.h"

/*Supported parameter types*/
typedef enum {INT_TYPE, REAL_TYPE, BOOLEAN_TYPE, STRING_TYPE, LIST_TYPE} param_t;

union param_value{
	int 			int_val;
	float 			real_val;
	Boolean 		bool_val;
	char			*str_val;
	struct ParameterList	*list_val;
};

/*Parameter object
 * a string with the name of the parameter
 * a union param_val to store the value of the parameter taken in.
 */
typedef struct Parameter{
	
	char * pname;
	param_t type;
	int required;
	Boolean hasVal;
	union param_value val;
	
}Parameter;

/*ParameterManager object
 * holds an array of Parameter objects, dynamically allocated
 */
typedef struct ParameterManager{
	
	int size;
	int registered;
	struct Parameter * array;
	
}ParameterManager;

/*Creates a new parameter manager object
  PRE: size is a positive integer (see note 1 below)
  POST: Returns a new parameter manager object initialized to be empty 
  * (i.e. managing no parameters) on success, NULL otherwise (memory allocation failure)
  */
ParameterManager * PM_create(int size);

/*Destroys a parameter manager object
  PRE: n/a
  POST: all memory associated with parameter manager p is freed; returns 1 on success, 0 otherwise
  */
int PM_destroy(ParameterManager *p);

/*Extract values for parameters from an input stream (see note 2 below)
  PRE: fp is a valid input stream ready for reading that contains the desired parameters
  POST: All required parameters, and those optional parameters present, are assigned values 
  * that are consumed from fp, respecting comment as a "start of comment to end of line" character
  * if not null ('\0'); returns non-zero on success, 0 otherwise
  * (parse error,memory allocation failure)
  */
int PM_parseFrom(ParameterManager *p, FILE *fp, char comment);

/*Register parameter for management
  PRE: pname does not duplicate the name of a parameter already managed
  POST: Parameter named pname of type ptype (see note 3 below) is registered with p
  * as a parameter; if required is zero the parameter will be considered optional,
  * otherwise it will be considered required; returns 1 on success, 0 otherwise 
  * (duplicate name, memory allocation failure)
  */
int PM_manage(ParameterManager *p, char *pname, param_t ptype, int required);

/*Test if a parameter has been assigned a value
  PRE: pname is currently managed by p
  POST: Returns 1 if pname has been assigned a value, 0 otherwise (no value, unknown parameter)
  */
int PM_hasValue(ParameterManager *p, char *pname);

/*Obtain the value assigned to pname
  PRE: pname is currently managed by p and has been assigned a value
  POST: Returns the value (see note 4 below) assigned to pname; result is
  * undefined if pname has not been assigned a value or is unknown
  */
union param_value PM_getValue(ParameterManager *p, char *pname);
