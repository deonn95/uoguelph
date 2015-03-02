/*Deon Naltchadjian
 * 0832759
 * Due Sept 29 2014
 * Assignment 1*/

#include "a1.h"

/*This function takes the number you want the root of and applies Newton's function via recursion.
 * xOrig is used to store the original number, where x is used to pass the new approximation in each iteration
 * app stores the new iteration and fabs is used to execute absolute function
 * once a close enough root  is found, it returns to main
 */

float newton(float x, float xOrig, float e){
	
	/*RECURSIVE*/
	
	float app;
	
	app = x / 2;	
			
	if(fabs((app * app) - xOrig) > e){
		return newton((xOrig / app + app), xOrig, e);
	}
	
	return app;

}

/* This function takes the number you want the root of and applies Newton's function via a loop
 * app is the approximation of the root, and while the degree of accuracy is lower than the degree of the approximation's
 * accuracy, the loop continues.
 * once a close enough root is found, it returns to main.
 */

float newtonNR(float x, float e){
	
	/*NON RECURSIVE*/
	
	float app;
		
	app = x / 2;
	
	while(fabs((app * app) - x) > e){
		app = (x / app + app) / 2;
	}
	return app;
}
