/* Deon Naltchadjian
 * 0832759
 * Nov 3rd 2014
 * Assignment 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct row{
	
	int array[10];
	int key;
	
}row;

typedef struct heap{
	
	row array[21]; /*skip key 0*/
	
}heap;

heap downHeap(heap, int);
void printHeap(heap);
