/* Deon Naltchadjian
 * 0832759
 * Oct 15 2014
 * Assignment 2*/

#include "q2.h"

int main(int argc, char * argv[]){
	
	if(argc < 2){
		printf("Not enough arguments. Exiting.\n");
	}
	else if(argc > 2){
		printf("Too many arguments. Exiting.\n");
	}
	else{
		
		int i, num1, num2, numToStack, answer;
		char c;
		stack s;
		
		newStack(&s);
		
		/* This loop goes through each character of the command line argument
		 * if it's a number push it to the top of the stack
		 * if it's an operator, get (pop) the two numbers and perform the given operation
		 * print the final result and exit.
		 */
		
		for(i = 0; i < strlen(argv[1]); i++){
			
			c = argv[1][i];
			if(isdigit(c)){
				numToStack = c - '0'; /*char to int conversion requires removal of ASCII*/
				push(&s, numToStack);
			}
			else{
				num2 = pop(&s);
				num1 = pop(&s);
				answer = doMath(c, num1, num2);
				push(&s, answer);
			}
		}
		printf("%s is equal to %d.\n", argv[1], answer);
	}
	
	return 0;
	
}

/*creates a new stack*/

void newStack(stack * s){
	s->top = -1;
}

/*provided in class*/

void push(stack * s, int val){
	if(s->top >= MAX - 1){
		/*stack is full*/	
	}
	else{
		s->top++;
		s->array[s->top] = val;
	}
}

/*provided in class*/

int pop(stack * s){
	int val;
	if(s->top < 0){
		/*stack is empty*/
	}
	else{
		val = s->array[s->top];
		s->top = s->top-1;
	}
	return val;
}

/*doMath function
 * 
 * Takes in the character and determines which operation to use, returns the answer after doing math
 */

int doMath(char c, int num1, int num2){
	
	int answer;
	
	if(c == '+'){
		answer = num1 + num2;
	}
	else if(c == '-'){
		answer = num1 - num2;
	}
	else if(c == '/'){
		answer = num1 / num2;
	}
	
	else if(c == '*'){
		answer = num1 * num2;
	}
	
	return answer;
	
}
