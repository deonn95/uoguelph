/* Deon Naltchadjian
 * 0832759
 * Oct 15 2014
 * Assignment 2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LETTERS 100

typedef struct car{
	
	char license [MAX_LETTERS];
	int mileage;
	char returnDate[MAX_LETTERS];
	struct car * next;
	
}car;

car * makeCar(char *, int, char *);
void addToEnd(struct car *, char *, int, char *);
car * addToFront(car *, char *, int, char *);
void addToMiddleAvailable(car *, char *, int, char *);
void addToMiddleRented(car *, char *, int, char *);
car * find(car *, char *, int);
void delete(car *, car *, char *, int);
void delFirst(car **);
void printList(struct car *);
int dateCompare(char *, char *);
int isValidDate(char *);
void saveFile(car *, car*, car*);
