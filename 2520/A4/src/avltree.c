/* Deon Naltchadjian
 * 0832759
 * Nov 24th 2014
 * Assignment 4
*/

#include "a4.h"

/* Main loop, prints my banner and then prompts you.
 * Pick one of the options, redirect to functions, you get the gist.
 * Only DELETION with an incorrect key does not work causing segfault, everything else should be fine.
 */
int main(){
	
	int loop, userIn;
	node * tree = NULL;
	node * finder = NULL;
	char * key;
	key = malloc(sizeof(char *) * 15);
	
	printf("\n\t\t/********************\\\n\t\t\\*Welcome to the AVL*/\n\t\t/*     Creator      *\\\n\t\t\\*                  */\n\t\t/*Deon  Naltchadjian*\\\n\t\t\\*     0832759      */\n\t\t/********************\\\n\n");
	
	loop = 1;
	while(loop == 1){
		printf("1. Initialization\n2. Find\n3. Insert\n4. Remove\n5. Check Height and Size\n6. Find All (above a given frequency)\n7. Exit\navl/> ");
		userIn = 0;
		scanf("%d", &userIn);
		switch (userIn){
			case 1: /*DONE (this is my personal checklist)*/
				tree = initialize();
				break;
			case 2: /*DONE*/
				printf("find key: ");
				scanf("%s", key);
				finder = find(tree, key);
				if(finder == NULL){
					printf("no_such_key\n");
				}
				else{
					printf("key: %s, frequency: %d\n", key, finder->frequency);
				}
				break;
			case 3: /*DONE*/
				printf("insert key: ");
				scanf("%s", key);
				tree = insert(key, tree);
				printf("key: %s, frequency: %d\n", key, find(tree, key)->frequency);
				break;
			case 4: /*ALMOST DONE (explained in Readme)...*/
				printf("remove key: ");
				scanf("%s", key);
				tree = removeNode(tree, key);
				break;
			case 5: /*DONE*/
				printf("height: %d, size: %d\n", totalHeight(tree, 0), countNodes(tree));
				break;
			case 6: /*DONE*/
				aboveFreq(tree, -1); 
				break;
			case 7: /*DONE*/
				printf("exiting\n");
				loop = 0;
				break;
			default:
				printf("Invalid user input.\n");
		}
	}
	return 0;
}

/* Gets max of two integers
 * Used to update height.
 */
int max(int x, int y){
	if(x > y){
		return x;
	}
	else{
		return y;
	}
}

/* Prompts for file input, should be located in the root folder.
 * Reads lines of file and parses keys
 * Creates tree using keys, returns the tree to main.
 */
node * initialize(){
	
	FILE * f;
	char filename[50];
	char read[1000];
	char * tok;
	node * tree = NULL;
	
	printf("filename: ");
	scanf("%s", filename);
	f = fopen(filename, "r");
	if(ferror(f)){
		printf("Error reading file.\n");
	}
	else{
		while(fgets(read, sizeof(read),f)){
			tok = strtok(read, " \n");
			while(tok != NULL){
				tree = insert(tok, tree);
				tok = strtok(NULL, " \n");
			}
		} 
	}
	fclose(f);
	
	return tree;
}

/* Creates a new node, initializing both children to NULL
 * Handles memory allocating etc.
 */
node * createNode(char * key){
	
	node * n = malloc(sizeof(node));
	n->key = malloc(sizeof(char *) * strlen(key) + 1);
	
	strcpy(n->key, key);
	n->left = NULL;
	n->right = NULL;
	n->frequency = 1;
	n->height = 0;
	return n;
}

/* Insert function inserts new node
 * Updates height of parent
 * Checks balance of parent, possibly fixes with rotations
 */
node * insert(char * key, node * n){
	
	int balanced;
	
	if(n == NULL){
		node * new = createNode(key);
		return new;
	}
	else{
		if(strcmp(key, n->key) < 0){
			n->left = insert(key, n->left);
		}
		else if(strcmp(key, n->key) > 0){
			n->right = insert(key, n->right);
		}
		else if(strcmp(key, n->key) == 0){
			n->frequency++;
		}
	}
	
	n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
	
	balanced = checkBalance(n);
	
	/*LL*/
	if(balanced > 1 && strcmp(key, n->left->key) < 0){
		return rotateR(n);
	}
	/*LR*/
	else if(balanced > 1 && strcmp(key, n->left->key) > 0){
		n->left = rotateL(n->left);
		return rotateR(n);
	}
	/*RR*/
	else if(balanced < -1 && strcmp(key, n->right->key) > 0){
		return rotateL(n);
	}
	/*RL*/
	else if(balanced < -1 && strcmp(key, n->right->key) < 0){
		n->right = rotateR(n->right);
		return rotateL(n);
	}
	/*Already balanced*/
	return n;
}

/* Left rotation as provided in labs
 * Used for balancing
 */
node * rotateL(node * z){
	
	node * y = z->right;
	node * T1 = y->left;
	y->left = z;
	z->right = T1;
	
	z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
	
}

/* Right rotation as provided in labs
 * Used for balancing
 */
node * rotateR(node * z){
	
	node * y = z->left;
	node * T1 = y->right;
	y->right = z;
	z->left = T1;
	
	z->height = max(getHeight(z->left), getHeight(z->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}

/* Checks to see if key exists, if it does:
 * If there is more than one, remove one from frequency
 * If there is one, delete it. DOES NOT WORK CORRECTLY :(
 * If it doesnt exist, update the user by saying "no_such_key"
 */
node * removeNode(node * n, char * key){
	
	if(n == NULL){
		return n;
	}
	
	node * finder;
	finder = find(n, key);
	
	/* If the frequency is more than one, delete one
	 * if not delete the node and fix the tree.
	 */
	if(finder == NULL){
		printf("no_such_key\n");
		return n;
	}
	if(finder->frequency > 1){
		finder->frequency--;
		printf("key: %s, frequency: %d\n", key, finder->frequency);
		return n;
	}
	else{
		node * del;
		if(finder->left == NULL && finder->right != NULL){
			del = finder->right;	
			finder = del;
			free(del);
		}
		else if(finder->left != NULL && finder->right == NULL){
			del = finder->left;
			finder = del;
			free(del);
		}
		else if(finder->left == NULL && finder->right == NULL){
			del = finder;
			finder = NULL;
			free(del);
		}
		else{ /*there's 2 children*/
			del = n->right;
			while(del->left != NULL){
				del = del->left;
			}
			strcpy(n->key, del->key);
			finder->right = removeNode(finder->right, del->key);
		}
	}
	
	if(finder == NULL){
		return n;
	}
	
	finder->height = max(getHeight(finder->left), getHeight(finder->right)) + 1;
	
	int balanced = checkBalance(finder);
	
	/*LL*/
	if(balanced > 1 && strcmp(key, finder->left->key) < 0){
		return rotateR(finder);
	}
	/*LR*/
	else if(balanced > 1 && strcmp(key, finder->left->key) > 0){
		finder->left = rotateL(finder->left);
		return rotateR(finder);
	}
	/*RR*/
	else if(balanced < -1 && strcmp(key, finder->right->key) > 0){
		return rotateL(finder);
	}
	/*RL*/
	else if(balanced < -1 && strcmp(key, finder->right->key) < 0){
	finder->right = rotateR(n->right);
		return rotateL(finder);
	}
	/*Already balanced*/
	printf("key: %s, frequency: 0\n", key);
	return n;
}

/* Checks for height so I don't have to check for NULL all the time.
 * 
 */ 
int getHeight(node * n){
	if(n == NULL){
		return -1;
	}
	else{
		return n->height;
	}
}

/* Calculates balance of tree using heights.
 */
int checkBalance(node * n){
	if(n == NULL){
		return 0;
	}
	else{
		int height = getHeight(n->left) - getHeight(n->right); 
		return height;
	}
	
}

/* Uses recursion to find a node with given key
 * If not found, returns NULL
 */
node * find(node * n, char * key){
	if(n == NULL){
		return NULL;
	}
	if(strcmp(key, n->key) < 0){
		return find(n->left, key);
	}
	else if(strcmp(key, n->key) > 0){
		return find(n->right, key);
	}
	else if(strcmp(key, n->key) == 0){
		return n;
	}
	else{
		return NULL;
	}
}

/* Counts total nodes in tree using inorder traversal.
 * Recursively calls itself to add up each child node and itself
 */
int countNodes(node * n){
	if(n == NULL){
		return 0;
	}
	else{
		return countNodes(n->left) + countNodes(n->right) + 1;
	}
}

/* Calculated total height of tree using inorder traversal
 * If the height of next node is greater, update tree.
 */
int totalHeight(node * n, int maxH){
	if(n != NULL){
		if(n->height > maxH){
			maxH = n->height;
		}
		return totalHeight(n->left, maxH);
		return totalHeight(n->right, maxH);
		if(n->height > maxH){
			maxH = n->height;
		}
	}
	return maxH;
}

/* On first call, takes input.
 * After input, uses inorder traversal to search tree
 * Checks if frequency is higher than given frequency
 * If it is, prints the node contents.
 */
void aboveFreq(node * n, int frequency){
	
	if(frequency == -1){
		printf("frequency: ");
		scanf("%d", &frequency);
	}
	
	if(n != NULL){
		aboveFreq(n->left, frequency);
		if(n->frequency >= frequency)
			printf("key: %s, frequency: %d\n", n->key, n->frequency);
		aboveFreq(n->right, frequency);
	}
}

/* Testing function, used in development to see if my input matches the sample
 * file on moodle.
 * Recursively goes through each node, beginning with leftmost child
 * Prints contents.
 */
void inorder(node * n){
	
	if(n != NULL){
		inorder(n->left);
		printf("In order: %s, count: %d, height: %d, bf: %d\n", n->key, n->frequency, n->height, checkBalance(n));
		inorder(n->right);
	}
}
