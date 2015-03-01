 /*********************************************
 * Deon Naltchadjian
 * 0832759
 * CIS*2750 A1
 * FINAL Due Jan 23 2015
 *********************************************/
 
#include "ParameterManager.h"


/*Creates a new parameter manager object
  PRE: size is a positive integer
  POST: Returns a new parameter manager object initialized to be empty 
  * (i.e. managing no parameters) on success, NULL otherwise (memory allocation failure)
  */
struct ParameterManager * PM_create(int size){
	
	printf("size to be malloced: %d\n", size);
	struct ParameterManager * pm;
	
	pm = malloc(sizeof(struct ParameterManager));
	
	if(size <= 0)  /*size too small*/
		return NULL;
	
	printf("Malloced parametermanager\n");
	pm->size = size;
	pm->registered = 0;	
	pm->array = malloc(sizeof(struct Parameter) * size);
	printf("Malloced the parameter array of size %d\n", size);
	if(pm->array == NULL)
		return NULL;
		
	return pm;
}

/*Destroys a parameter manager object
  PRE: n/a
  POST: all memory associated with parameter manager p is freed; returns 1 on success, 0 otherwise
  */
int PM_destroy(struct ParameterManager *p){
	
	int i;
	
	if(p == NULL){
		return 0;
	}
	
	for(i = 0; i < p->size; i++){
		if(p->array[i].pname != NULL){
			free(p->array[i].pname);
			if(p->array[i].type == LIST_TYPE){
				if((List_destroy(p->array[i].val.list_val->list)) == 0){
					fprintf(stderr, "Error freeing list\n");
					return 0;
				}
				PL_destroy(p->array[i].val.list_val);
			}
			else if(p->array[i].type == STRING_TYPE){
				free(p->array[i].val.str_val);
			}
		}
	}
	free(p->array);
	free(p);
	return 1;
	
}

/*Extract values for parameters from an input stream (see note 2 below)
  PRE: fp is a valid input stream ready for reading that contains the desired parameters
  POST: All required parameters, and those optional parameters present, are assigned values 
  * that are consumed from fp, respecting comment as a "start of comment to end of line" character
  * if not null ('\0'); returns non-zero on success, 0 otherwise
  * (parse error,memory allocation failure)
  */
int PM_parseFrom(struct ParameterManager *p, FILE *fp, char comment){
	
	char c = ' ';
	int i, parsing, longestParam = 0, pos = 0, listElements;
	char * str;
	Boolean commentState = false, nameState = true, valueState = false, stringState = false, emptyList = true;
	
	for(i = 0; i < p->registered; i++){
		if(strlen(p->array[i].pname) > longestParam){
			longestParam = strlen(p->array[i].pname);
		}
	}
	
	/*used to store our param name in the parse*/
	str = malloc(sizeof(char) * 1025);
	
	do{
		c = fgetc(fp);
		if(c == comment){ /*starts a comment, so all chars are ignored till newline*/
			commentState = true;
		}
		else if(c == '\n'){ /*ends the comment, now the parser is open to having all chars*/
			commentState = false;
			pos = 0;
		}
		else if(c == ' ' || c == '\t'){ /*whitespace*/
			pos = 0;
		}
		else{
			if(commentState == false){
				/*have to find the name of variable first*/
				if(nameState == true){
					pos = 0;
					str[pos] = c;
					while(c != '=' && c != ' ' && c != '\t' && c != '\n' && c != EOF){
						c = fgetc(fp);
						if(c == comment){
							do{
								c = fgetc(fp);
							}while(c != '\n');
						}
						if(c != '=' && c != ' ' && c != '\t' && c != '\n'){
							pos++;
							str[pos] = c;
						}
					}
					for(i = 0; i < p->registered; i++){
						/*if name of param is found*/
						if(strcmp(str, p->array[i].pname) == 0){
							parsing = i;
							i = p->registered;
							nameState = false;
							valueState = true;
						}
					}
					memset(str, 0, strlen(str));
				}
				/*done getting the name, now get values*/
				else if (valueState == true){
					pos = 0;
					if(c != '='){
						str[pos] = c;
						pos++;
					}
					if(p->array[parsing].type != STRING_TYPE && p->array[parsing].type != LIST_TYPE){
						while(c != ';' && c != EOF){
							c = fgetc(fp);
							if(c == comment){
								do{
									c = fgetc(fp);
								}while(c != '\n');
							}
							if(c != '=' && c != ' ' && c != '\t' && c != '\n' && c != ';' && c != EOF){
								str[pos] = c;
								pos++;
							}
						}
					}
					if(p->array[parsing].type == INT_TYPE){
						p->array[parsing].val.int_val = atoi(str);
						if(str[0] != '0' && p->array[parsing].val.int_val == 0){
							fprintf(stderr, "Parse error, int value set to non-int");
						}
					}
					else if(p->array[parsing].type == REAL_TYPE){
						p->array[parsing].val.real_val = atof(str);
						if(str[0] != '0' && p->array[parsing].val.real_val == 0){
							fprintf(stderr, "Parse error, float value set to non-float\n");
							return 0;
						}
					}
					else if(p->array[parsing].type == BOOLEAN_TYPE){ /*Boolean DONE*/
						if(strcmp(str, "true") == 0){
							p->array[parsing].val.bool_val = true;
							
						}
						else if(strcmp(str, "false") == 0){
							p->array[parsing].val.bool_val = false;
						}
						else{
							fprintf(stderr, "Parse error, boolean value set to non-boolean\n");
							return 0;
						}
					}
					else if(p->array[parsing].type == STRING_TYPE){
						pos = 0;
						while(c != ';' && c != EOF){
							if(c != '\"'){
								c = fgetc(fp);
							}
							if(c == comment){
								do{
									c = fgetc(fp);
								}while(c != '\n');
							}
							if(c == '\"'){
								stringState = true;
								do{
									c = fgetc(fp);
									if(c != '\"'){
										str[pos] = c;
										pos++;
									}
								}while(c != '\"');
								c = fgetc(fp);
							}
						}
						if(stringState == true){
							p->array[parsing].val.str_val = malloc(sizeof(char) * strlen(str) + 1);
							strcpy(p->array[parsing].val.str_val, str);
							stringState = false;
						}
						else{
							fprintf(stderr, "Parse error, string value set to non-string value\n");
							return 0;
						}
					}
					else if(p->array[parsing].type == LIST_TYPE){
						emptyList = false;
						listElements = 0;
						while(c != ';' && c != EOF){
							if(c != '{'){
								c = fgetc(fp);
							}
							if(c == '{'){ /*list begins*/
								while(c != '}'){
									c = fgetc(fp);
									if(c == comment){
										do{
											c = fgetc(fp);
										}while(c != '\n');
									}
									if(c == '}' && listElements < 1){
										emptyList = true;
										p->array[parsing].val.list_val = PL_create();
									}
									if(c == '\"'){
										listElements++;
										c = fgetc(fp);
										pos = 0;
										while(c != '\"'){
											str[pos] = c;
											pos++;
											c = fgetc(fp);
										}
									}
									if(strlen(str) > 0 && emptyList == false){
										if(p->array[parsing].val.list_val == NULL){
											p->array[parsing].val.list_val = PL_create();
											p->array[parsing].val.list_val->list = List_create(str);
											p->array[parsing].val.list_val->front= p->array[parsing].val.list_val->list;
										}
										else{
											List_addNext(p->array[parsing].val.list_val->list, str);
										}
									}
									memset(str, 0, strlen(str));
								}
							}
						}
					}
					p->array[parsing].hasVal = true;
					nameState = true;
					valueState = false;
					memset(str, 0, strlen(str));
				}
			}
		}
		
	}while(c != EOF);
	
	for(i = 0; i < p->registered; i++){
		if(p->array[i].hasVal == false && p->array[i].required == 1){
			fprintf(stderr, "Parse error, required parameter not found: %s\n", p->array[i].pname);
			return 0;
		}
	}
	
	free(str);
	
	return 1;
}

/*Register parameter for management
  PRE: pname does not duplicate the name of a parameter already managed
  POST: Parameter named pname of type ptype (see note 3 below) is registered with p
  * as a parameter; if required is zero the parameter will be considered optional,
  * otherwise it will be considered required; returns 1 on success, 0 otherwise 
  * (duplicate name, memory allocation failure)
  */
int PM_manage(struct ParameterManager *p, char *pname, param_t ptype, int required){
	
	printf("Called PM_Manage\n");
	
	if(p->registered == p->size){
		fprintf(stderr, "Error, size of parameterManager reached\n");
		return 0;
	}
	printf("Checked size of pm compared to registered\n");
	int i;
	
	for(i = 0; i < p->size; i++){
		if(p->array[i].pname == NULL){
			i = p->size;
		}
		else{
			if(strcmp(pname, p->array[i].pname) == 0){
				fprintf(stderr, "Registering parameter error, duplicate name\n");
				return 0;
			}
		}
	}
	
	printf("Checked name if it is duplicate\n");
	
	p->array[p->registered].pname = malloc(sizeof(char) * strlen(pname) + 1);
	if(pname == NULL){
		fprintf(stderr, "Error, malloc failure\n");
		return 0;
	}
	
	printf("Malloced space for name of param\n");
	strcpy(p->array[p->registered].pname, pname);
	p->array[p->registered].type = ptype;
	p->array[p->registered].required = required;
	p->array[p->registered].hasVal = false;
	p->registered++;
	
	return 1;
	
}

/*Test if a parameter has been assigned a value
  PRE: pname is currently managed by p
  POST: Returns 1 if pname has been assigned a value, 0 otherwise (no value, unknown parameter)
  */
int PM_hasValue(struct ParameterManager *p, char *pname){
	
	int i;
	
	for(i = 0; i < p->size; i++){
		if(p->array[i].pname == NULL){
			fprintf(stderr, "Error, unknown param\n");
			return 0;
		}
		else{
			if(strcmp(pname, p->array[i].pname) == 0){
				if(p->array[i].hasVal == false){
					fprintf(stderr, "No value\n");
					return 0;
				}
				i = p->size;
			}
		}
	}	
	
	fprintf(stdout, "%s has value\n", pname);
	return 1;
	
}

/*Obtain the value assigned to pname
  PRE: pname is currently managed by p and has been assigned a value
  POST: Returns the value (see note 4 below) assigned to pname; result is
  * undefined if pname has not been assigned a value or is unknown
  */
union param_value PM_getValue(struct ParameterManager *p, char *pname){
	
	int i;
	union param_value undef;
	
	for(i = 0; i < p->size; i++){
		if(p->array[i].pname == NULL){
			fprintf(stderr, "Error, unknown param\n");
			return undef;
		}
		else{
			if(strcmp(pname, p->array[i].pname) == 0){
				if(p->array[i].hasVal == false){
					fprintf(stderr, "No value\n");
					return undef;
				}
				else{
					return p->array[i].val;
				}
			}
		}
	}
	
	return undef;
}
