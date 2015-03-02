/*Deon Naltchadjian
 * 0832759
 * Due Sept 29 2014
 * Assignment 1*/

#include "q1.h"

/* The main function controls the menu
 * Each function can be accessed by typing the respective letter.
 * the char 'choice' stores the user's character and accesses each option.
 * most of main is in a loop, which contains the text menu
 * it also handles all input, ie. the number to be put into netwon's function
 */

int main(){
	
	int loop, m, n, aAnswer;
	float x, e, nAnswer;
	char choice;
	
	choice = 'c';
	loop = 1;
	m = 0;
	n = 0;
	x = 0;
	e = 0;
	aAnswer = 0;
	nAnswer = 0;
		
	/*this loop allows you to choose which of the functions to view, or exit at any time by taking a char as input and comparing the three cases.*/
	while(loop == 1){
		
		printf("Type 'c' to see the Carbon permutation function.\nType 'a' to see Ackermann's function.\nType 'n' for Newton's root function (RECURSIVE).\nType 'N' for Newton's root function (NON-RECURSIVE).\nType 'e' to exit.\n");
		scanf(" %c", &choice);
		fflush(stdin);
		
		if(choice == 'c'){
			carbon();
		}
		else if(choice == 'a'){
			printf("Please enter two natural numbers:\n");
			scanf("%d%d", &m, &n);
			aAnswer = ackermann(m, n);
			printf("A(%d, %d) = %d\n\n", m, n, aAnswer);
		}
		else if(choice == 'n'){
			printf("Please enter the number you would like to see the root of\nfollowed by the degree of accuracy:\n");
			scanf("%f%f", &x, &e);
			nAnswer = newton(x, x, e);
			printf("Newton's root of %f with accuracy %f: %f\n", x, e, nAnswer);
		}
		else if(choice == 'N'){
			printf("Please enter the number you would like to see the root of\nfollowed by the degree of accuracy:\n");
			scanf("%f%f", &x, &e);
			nAnswer =  newtonNR(x, e);
			printf("Newton's root of %f with accuracy %f: %f\n", x, e, nAnswer);
		}
		else if(choice == 'e'){
			loop = 0;
		}
		else{
			printf("Invalid input\n");
		}
	}
	return 0;
}


