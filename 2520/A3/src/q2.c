/* Deon Naltchadjian
 * 0832759
 * Nov 3rd 2014
 * Assignment 3
*/

#include "q2.h"

/*main
 * read in the f.dat file, turn each row into a row object
 * close the file
 * run the downHeap algorithm till it is ordered correctly
 * print the elements in the heap
 */

int main(){
	
	FILE* f;
	char read[1000]; /*used to read in file*/
	char * tok;
	int i, j, parse;
	row rows[20];
	heap h;
	
	f = fopen("docs/f.dat", "r");
	tok = malloc(sizeof(char) * 10);
	
	while(fgets(read, sizeof(read),f)){
		parse = 0;
		tok = strtok(read, " ");
		while(parse < 10){
			rows[i].array[parse] = atoi(tok);
			tok = strtok(NULL, " " );
			parse++;
		}
		i++;
	}
	
	fclose(f);
	
	for(i= 0; i < 20; i++){
		rows[i].key = rows[i].array[0] + rows[i].array[1] + rows[i].array[2];
		h.array[i + 1] = rows[i];
	}
	
	for(i = 5; i > 0; i--){ /*start at the last node with children*/
		for(j = 10; j > 0; j--){
			h = downHeap(h, j);
		}
	}
	
	printf("Sorted:\n");
	printHeap(h);
	
	return 0;
	
}

/*downHeap
 * checks the right child, if it exists, is less that the parent and less than the left, swap it with parent.
 * if not, then check if the left child is less than the parent, and swap if it is.
 * return the altered heap.
 */
heap downHeap(heap h, int parent){

	int left = parent * 2;
	int right = (parent * 2) + 1;
	row temp;
	
	if (right >= 21){ /*make sure we do not compare invalid data*/
		right = left;
	}
	
	if(h.array[right].key < h.array[parent].key && h.array[right].key <= h.array[left].key){ /*if right child exists, is greater than parent and less than */
		temp = h.array[right];
		h.array[right] = h.array[parent];
		h.array[parent] = temp;
		/*printf("Swapping right %d with %d at index %d\n", h.array[parent].key, h.array[right].key, parent);*/
	}
	else if(h.array[left].key < h.array[parent].key){
		temp = h.array[left];
		h.array[left] = h.array[parent];
		h.array[parent] = temp;
		parent = right;
		/*printf("Swapping left %d with %d at index %d\n", h.array[parent].key, h.array[left].key, parent);*/
	}
	
	return h;
	
}


/*printHeap
 * the printHeap method takes every element of the rows array in the heap and prints the key as well as the values in the array.
 */
void printHeap(heap h){
	
	int i;
	for(i = 1; i < 21; i++){
		printf("Key: %d. Array: %d %d %d %d %d %d %d %d %d %d\n", h.array[i].key, h.array[i].array[0], h.array[i].array[1], h.array[i].array[2], h.array[i].array[3], h.array[i].array[4], h.array[i].array[5], h.array[i].array[6], h.array[i].array[7], h.array[i].array[8], h.array[i].array[9]);
	}
}

