/*Deon Naltchadjian
 * 0832759
 * Due Sept 29 2014
 * Assignment 1*/

#include "a1.h"

/* This function follows the formula given on the A1 pdf file exactly.
 * If m is zero, return n + 1
 * If m is greater than zero and n is zero, recall the ackermann function with m-1 and 1 as parameters
 * If m and n are nonzero natural numbers, recall ackermann function with m-1 and another ackerman with m and n-1 as parameters.
 */

int ackermann(int m, int n){
	
	if(m == 0 && n >= 0){
		return n + 1;
	}
	else if(m > 0 && n == 0){
		return ackermann(m - 1, 1);
	}
	else if(m > 0 && n > 0){
		return ackermann(m - 1, ackermann(m, n - 1));
	}
	
	return 0;
}
