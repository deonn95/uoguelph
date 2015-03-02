/* Deon Naltchadjian
 * 0832759
 * Oct 15 2014
 * Assignment 2*/
 
#include "q1.h"

int main(){
	
	char * menuStr, * license, * mileStr, *returnStr, *tok; /*menuStr for menu input, license mileStr returnStr for car creation, tok for strtok "," character*/
	char read[1000]; /*used to read lines of file*/
	int menuOption, mileage, availableNum, rentedNum, repairNum, listNum, i, dateComp;
	struct car * available, * rented, * repair, * found; /*found is used for find operations, other three are each their own lists*/
	double profit, totalInc;
		
	menuStr = malloc(sizeof(char) * MAX_LETTERS);
	license = malloc(sizeof(char) * MAX_LETTERS);
	mileStr = malloc(sizeof(char) * MAX_LETTERS);
	returnStr = malloc(sizeof(char) * MAX_LETTERS);
	tok = malloc(sizeof(char) * MAX_LETTERS);
	
	FILE * f;
	f = fopen("docs/cars.txt", "r");
	
	listNum = 0;
	availableNum = 0;
	rentedNum = 0;
	repairNum = 0;
	profit = 0;
	totalInc = 0;
	
	available = NULL;
	rented = NULL;
	repair = NULL;
	
	/* This handles file reading.
	 * Reads the header, selects which list to add elements to
	 * strtok at the "," in the text file "cars.txt"
	 * initialize a list with one element, add to the end of the list in each iteration as the values are already stored in the correct order.
	 */
	
	while(fgets(read, sizeof(read),f)){
		i = 0;
		if(strcmp("AVAILABLEFORRENT\n", read) == 0){
			listNum = 1;
		}
		else if(strcmp("CURRENTLYRENTED\n", read) == 0){
			listNum = 2;
		}
		else if(strcmp("CURRENTLYINREPAIR\n", read) == 0){
			listNum = 3;
		}
		else{
			tok = strtok(read, ",");
			while(i < 3){
				if(i == 0){
					strcpy(license, tok);
				}
				else if(i == 1){
					strcpy(mileStr, tok);
					mileage = strtol(mileStr, (char **) NULL, 10);
				}
				else if(i == 2){
					strcpy(returnStr, tok);
				}
				i++;
				tok = strtok(NULL, ",");
			}
			
			switch(listNum){
				case 1:
					if(available == 0){
						available = makeCar(license, mileage, returnStr);
					}
					else{
						addToEnd(available, license, mileage, returnStr);
					}
					availableNum++;
					break;
				case 2:
					if(rented == NULL){
						rented = makeCar(license, mileage, returnStr);
					}
					else{
						addToEnd(rented, license, mileage, returnStr);
					}
					rentedNum++;
					break;
				case 3:
					if(repair == NULL){
						repair = makeCar(license, mileage, returnStr);
					}
					else{
						addToEnd(repair, license, mileage, returnStr);
					}
					repairNum++;
			}
		}
	}
	if(ferror(f)){
		printf("Error reading file\n");
	}
	fclose(f);
	
	/* The main command loop
	 * Options 1-7 do various commands.
	 * 1. Creates a new car pointer, searches for appropriate place in available list, places in list.
	 * 2. Deletes car from rented list, adds it to available list, calculates profit and adds it to total income.
	 * 3. Deletes car from rented list, adds it to repair list, calculates profit and adds it to total income.
	 * 4. Deletes car from repair list, adds to available list in appropriate place.
	 * 5. Removes first element in available list, prompts for a return date and adds it to appropriate place in rented list.
	 * 6. Prints contents of all lists.
	 * 7. Exits, prints total income and writes to file new lists.
	 */
	
	do{
		menuOption = 0;
		printf("1. add a new car to the available-for-rent list,\n2. add a returned car to the available-for-rent list,\n3. add a returned car to the repair list,\n4. transfer a car from the repair list to the available-for-rent list,\n5. rent the first available car,\n6. print all the lists,\n7. quit.\n");
		scanf("%s", menuStr);
		menuOption = (int) strtol(menuStr, (char **) NULL, 10);
		
		switch(menuOption){
			case 1:
				printf("Adding new car to available for-rent list\n");
				printf("Please enter a license plate (AAAA111), and a mileage (1001) individually:\n");
				scanf("%s%s", license, mileStr);
				mileage = strtol(mileStr, (char **) NULL, 10);
				strcpy(returnStr, "0");
				if(available->mileage >= mileage){
					available = addToFront(available, license, mileage, returnStr);
				}
				else{
					addToMiddleAvailable(available, license, mileage, returnStr);
				}
				printf("Added new car to available list\n");
				break;
			case 2:
				printf("Adding returned car to available for-rent list\n");
				printf("Please enter a license plate (AAAA111), and a mileage (1001) individually:\n");
				scanf("%s%s", license, mileStr);
				mileage = strtol(mileStr, (char **) NULL, 10);
				found = find(rented, license, mileage);
				if(found == NULL){
					printf("Could not find the car you entered\n");
				}
				else{
					printf("Found the car you entered\n");
					if(rented->mileage != mileage){
						delete(rented, rented, license, mileage);
					}
					else{
						delFirst(&rented);
					}
					printf("Removed from the rented list\n");
					if(available->mileage > mileage){
						available = addToFront(available, license, mileage, "0");
					}
					else{
						addToMiddleAvailable(available, license, mileage, "0");
					}
					printf("Added to available list\n");
					if(mileage > 100){
						profit = ((mileage - 100) * 0.15) + 40;
					}
					else{
						profit = 40;
					}
					totalInc += profit;
					printf("Profit of transaction: $%.2lf\n", profit);
				}
				break;
			case 3:
				printf("Adding returned car to repair list\n");
				printf("Please enter a license plate (AAAA111), and a mileage (1001) individually:\n");
				scanf("%s%s", license, mileStr);
				mileage = strtol(mileStr, (char **) NULL, 10);
				found = find(rented, license, mileage);
				if(found == NULL){
						printf("Could not find the car you entered\n");
				}
				else{
					printf("Found the car you entered\n");
					if(rented->mileage != mileage){
						delete(rented, rented, license, mileage);
					}
					else{
						delFirst(&rented);
					}
					printf("Removed from the rented list\n");
					repair = addToFront(repair, license, mileage, "0");
					printf("Added to repair list\n"); 
					if(mileage > 100){
						profit = ((mileage - 100) * 0.15) + 40;
					}
					else{
						profit = 40;
					}
					totalInc += profit;
					printf("Profit of transaction: $%.2lf\n", profit);
				}
				break;
			case 4:
				printf("Transeferring repair to available for-rent list\n");
				printf("Please enter a license plate (AAAA111), and a mileage (1001) individually:\n");
				scanf("%s%s", license, mileStr);
				mileage = strtol(mileStr, (char **) NULL, 10);
				found = find(repair, license, mileage);
				if(found == NULL){
						printf("Could not find the car you entered\n");
				}
				else{
					printf("Found the car you entered\n");
					if(repair->mileage != mileage){
						delete(repair, rented, license, mileage);
					}
					else{
						delFirst(&repair);
					}
					printf("Removed from the repair list\n");
					if(available->mileage > mileage){
						available = addToFront(available, license, mileage, "0");
					}
					else{
						addToMiddleAvailable(available, license, mileage, "0");
					}
					printf("Added to available for-rent list\n"); 
				}
				break;
			case 5:
				printf("Renting first available car\n");
				printf("Enter a return date (YYMMDD)\n");
				scanf("%s", returnStr);
				if(isValidDate(returnStr) == 0){
					dateComp = dateCompare(returnStr, rented->returnDate);
					if(dateComp != 0){
						rented = addToFront(rented, available->license, available->mileage, returnStr);
					}
					else{
						addToMiddleRented(rented, available->license, available->mileage, returnStr);
					}
					delFirst(&available);
					printf("Car Rented\n");
				}
				else{
					printf("Invalid date format\n");
				}
				break;
			case 6:
				printf("Printing all lists\nAvailable:\n");
				printList(available);
				printf("Rented:\n");
				printList(rented);
				printf("In repair:\n");
				printList(repair);
				break;
			case 7:
				printf("Quitting\n");
				printf("Total Income: $%.2lf\n", totalInc);
				saveFile(available, rented, repair);
				break;
			default:
				printf("Invalid command.\n");
		}	
	}while (menuOption != 7);
	
	free(menuStr);
	free(license);
	free(mileStr);
	free(returnStr);
	
	return 0;
	
}

/*makes a new car object, initializes next to NULL, returns said car
 */

car * makeCar(char * license, int mileage, char * returnDate){
	
	car * cp;
	if((cp = malloc(sizeof(car))) == NULL){
		printf("dynamic allocation failed\n");
		exit(0);
	}
	strcpy(cp->license, license);
	cp->mileage = mileage;
	strcpy(cp->returnDate, returnDate);
	cp->next = NULL;
	return cp;
	
}

/* creates a new car, adds to the end of the list.
 * taken from lecture notes.
 */

void addToEnd(car * sp, char * license, int mileage, char * returnDate){
	car * newCar = makeCar(license, mileage, returnDate);
	
	if(sp == NULL){
		sp = newCar;
		return;
	}
	
	while(sp->next != NULL){
		sp = sp->next;
	}
	newCar->next = sp->next;
	sp->next = newCar;
}

/* Adds to the front of the list, creating a new car.
 */

car * addToFront(car * sp, char * license, int mileage, char * returnDate){
	car * newCar = makeCar(license, mileage, returnDate);
	
	if(sp == NULL){
		return newCar;
	}
	
	newCar->next = sp;
	
	return newCar;
}

/* creates a new car, Adds to the middle or end of the Available list.
 * compares the mileage of two nodes, if the node in the list has a greater mileage, add it in that place
 * if not, repeat on the next pointer
*/

void addToMiddleAvailable(car *sp, char *license, int mileage, char *returnDate){
	
	car * newCar = makeCar(license, mileage, returnDate);
	car * dummy;
	
	if(sp == NULL){
		sp = newCar;
		return;
	}
	
	while(sp->next != NULL){
		dummy = sp->next;
		if(dummy->mileage > mileage){
			break;
		}
		sp = sp->next;
	}
	
	newCar->next = sp->next;
	sp->next = newCar;
	
}

/* creates new car, Adds to the middle or end of the Rented list.
 * compares the dates of two nodes, if the node in the list has a greater date, add it in that place
 * if not, repeat on the next pointer
*/

void addToMiddleRented(car *sp, char *license, int mileage, char *returnDate){
	
	car * newCar = makeCar(license, mileage, returnDate);
	car * dummy;
	
	if(sp == NULL){
		sp = newCar;
		return;
	}
	
	while(sp->next != NULL){
		dummy = sp->next;
		if(dateCompare(returnDate, dummy->returnDate) == 0){
			break;
		}
		sp = sp->next;
	}
	
	newCar->next = sp->next;
	sp->next = newCar;
	
}

/* Finds a node with the given mileage and license
 * searches the list's next pointers to get the next values, if they match, return that car
 */

car * find(car * sp, char * license, int mileage){
	
	while(sp->next != NULL && strcmp(sp->license, license) != -1){
		sp = sp->next;
	}
	if(sp->mileage == mileage){
		return sp;
	}
	else{
		return NULL;
	}
}

/* deletes a node at a given index, determined by main.
 * maintains rest of list.
 * uses a temp node to go through the list, and goes through it again with one less iteration
 * deletes the node before the one reached by temp. 
 */

void delete(car * sp, car * current, char * license, int mileage){
	
	int i = 0, j = 0;
	struct car * temp;
	while(strcmp(current->license, license) != 0 && current->next != NULL){
		current = current->next;
		i++;
	}
	while(j < i - 1){
		sp = sp->next;
		j++;
	}
	
	temp = sp->next;
	sp->next = temp->next;
	free(temp);
	
}

/* Deletes the first node in the given list, maintains rest of list.
 * 
 */

void delFirst(car ** sp){
	
	struct car * temp = *sp;
	if(temp == NULL){
		return;
	}
	*sp = temp->next;
	free(temp);
	
}

/* Goes through the given list and prints each iteration in a readable format.
 * 
 */

void printList(car * sp){
	if(!(strcmp(sp->returnDate, "0") == 0)){
		while(sp->next != NULL){
			printf("License: %s, Mileage: %dkm, Return Date: %s.\n", sp->license, sp->mileage, sp->returnDate);
			sp = sp->next;
		}
		printf("License: %s, Mileage: %dkm, Return Date: %s.\n", sp->license, sp->mileage, sp->returnDate);
	}
	else{
		while(sp->next != NULL){
			printf("License: %s, Mileage: %dkm.\n", sp->license, sp->mileage);
			sp = sp->next;
		}
		printf("License: %s, Mileage: %dkm.\n", sp->license, sp->mileage);
	}
}

/* converts each set of 2 digits to their own integers
 * returns 0 if date 1 is greater than date 2
 * returns 1 if date 1 is less than date 2*/

int dateCompare(char * returnDate1, char * returnDate2){
	
	char yearStr1[3];
	char yearStr2[3];
	char monthStr1[3];
	char monthStr2[3];
	char dayStr1[3];
	char dayStr2[3];
	int year1, year2, month1, month2, day1, day2;
	
	yearStr1[0] = returnDate1[0];
	yearStr1[1] = returnDate1[1];
	monthStr1[0] = returnDate1[2];
	monthStr1[1] = returnDate1[3];
	dayStr1[0] = returnDate1[4];
	dayStr1[1] = returnDate1[5];
	yearStr2[0] = returnDate2[0];
	yearStr2[1] = returnDate2[1];
	monthStr2[0] = returnDate2[2];
	monthStr2[1] = returnDate2[3];
	dayStr2[0] = returnDate2[4];
	dayStr2[1] = returnDate2[5];
	
	year1 = strtol(yearStr1, (char **) NULL, 10);
	month1 = strtol(monthStr1, (char **) NULL, 10);
	day1 = strtol(dayStr1, (char **) NULL, 10);
	year2 = strtol(yearStr2, (char **) NULL, 10);
	month2 = strtol(monthStr2, (char **) NULL, 10);
	day2 = strtol(dayStr2, (char **) NULL, 10);
	
	if(year1 >= year2){
		if(month1 >= month2){
			if(day1 >= day2){
				return 0;
			}
			else{
				return 1;
			}
		}
		else{
			return 1;
		}
	}
	else{
		return 1;
	}
}

/*checks to see if date is valid, returning 0 on yes
 * 1 on invalid.*/

int isValidDate(char* date){
	
	int i;
	for(i = 0; i < 6; i++){
		if(!isdigit(date[i])){
			return 1;
		}
	}
	return 0;
	
}

/* Creates the final save file to be read the next time the file is opened
 * goes through each linked list after adding appropriate header
 * prints the details in the appropriate format
 * closes file.
 */

void saveFile(car * available, car * rented, car * repair){
	
	FILE * f;
	f = fopen("docs/cars.txt", "w");
	fprintf(f, "AVAILABLEFORRENT\n");
	while(available->next != NULL){
		fprintf(f, "%s,%d,%s,\n", available->license, available->mileage, available->returnDate);
		available = available->next;
	}
	fprintf(f, "%s,%d,%s,\n", available->license, available->mileage, available->returnDate);
	
	fprintf(f, "CURRENTLYRENTED\n");
	while(rented->next != NULL){
		fprintf(f, "%s,%d,%s,\n", rented->license, rented->mileage, rented->returnDate);
		rented = rented->next;
	}
	fprintf(f, "%s,%d,%s,\n", rented->license, rented->mileage, rented->returnDate);
	
	fprintf(f, "CURRENTLYINREPAIR\n");
	while(repair->next != NULL){
		fprintf(f, "%s,%d,%s,\n", repair->license, repair->mileage, repair->returnDate);
		repair = repair->next;
	}
	fprintf(f, "%s,%d,%s,\n", repair->license, repair->mileage, repair->returnDate);
	
	fclose(f);
	
}
