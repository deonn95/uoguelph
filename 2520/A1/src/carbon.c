/*Deon Naltchadjian
 * 0832759
 * Due Sept 29 2014
 * Assignment 1*/

#include "a1.h"

/* This function contains a character string with the letters "carbon" and performs 6 for loops,
 * checking if each of the letters have been repeated. If not, it puts the letters together and
 * prints them out*/

void carbon(){
	
	int i,j,k,l,m,n;
	
	char cStr [6];
	strcpy(cStr, "carbon");
	
	for(i = 0; i < 6; i++){
		
		for(j = 0; j < 6; j++){
			
			for(k = 0; k < 6; k++){
				
				for(l = 0; l < 6; l++){

					for(m = 0; m < 6; m++){
						
						for(n = 0; n < 6; n++){
							if(cStr[n] == cStr[m] || cStr[n] == cStr[l] || cStr[n] == cStr[k] || cStr[n] == cStr[j] || cStr[n] == cStr[i]){
								
							}
							else if(cStr[m] == cStr[l] || cStr[m] == cStr[k] || cStr[m] == cStr[j] || cStr[m] == cStr[i]){
								
							}
							else if(cStr[l] == cStr[k] || cStr[l] == cStr[j] || cStr[l] == cStr[i]){
								
							}
							else if(cStr[k] == cStr[j] || cStr[k] == cStr[i]){
								
							}
							else if(cStr[j] == cStr[i]){
								
							}
							else{
								printf("%c%c%c%c%c%c", cStr[i], cStr[j], cStr[k], cStr[l], cStr[m], cStr[n]);
								printf("\n");
							}
						}
					}
				}
			}
		}
	}

		
}

/*I attempted recursion but I couldn't get the function to work, hence the below functions are not in use.
 * The strMix function was supposed to take the first given character of the carbon string and the last, then use a loop to swap
 * the characters and check all possiblities.
 * The charSwitch function was going to be used to simply swap the characters, very easy function

void strMix(char * cStr, int startChar, int endChar){
	
	int i;
	
	if(startChar == endChar){
		printf("%s\n", cStr);
	}
	
	for(i = startChar; i < endChar; i++){
		
		charSwitch(cStr[startChar], cStr[i]);
		strMix(cStr, startChar + 1, endChar);
		
	}
	
}

void charSwitch(char c1, char c2){
	
	char tempChar;
	tempChar = c1;
	c1 = c2;
	c2 = tempChar;
}

*/
