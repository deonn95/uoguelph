/* Deon Naltchadjian
 * 0832759
 * Nov 3rd 2014
 * Assignment 3
*/

#include "q2.h"

int main(){
	
	int loop = 1;
	int userIn;
	char userStr[100];
	
	printf("Enter a mathematical expression using parentheses\n");
	scanf("%s", userStr);
	
	while(loop == 1){
		printf("1. Display\n2. Preorder\n3. Inorder\n4. Postorder\n5. Update\n6. Calculate\n7. Exit\n");
		scanf("%d", &userIn);
		switch (userIn){
			case 1:
				printf("Displaying expression.\n");
				break;
			case 2:
				printf("Preordering expression.\n");
				break;
			case 3:
				printf("Inordering expression.\n");
				break;
			case 4:
				printf("Postordering expression.\n");
				break;
			case 5:
				printf("Updating.\n");
				break;
			case 6:
				printf("Calculating.\n");
				break;
			case 7:
				printf("Exiting.\n");
				loop = 0;
				break;
			default:
				printf("Invalid user input.\n");
		}
	}
	
	return 0;
	
}
