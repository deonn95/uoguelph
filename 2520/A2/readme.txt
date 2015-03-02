Deon Naltchadjian
0832759
Oct 15 2014

Q1 HOW TO:
To run the car list program, after making the executable, type "./bin/q2"
No command line arguments are needed.
Select between options 1-7 and follow the prompts.
This program reads and writes to "docs/cars.txt"
"docs/carsData.txt" was used as a test file to get file writing working properly

SAMPLE Q1:

./bin/q1
1. add a new car to the available-for-rent list,
2. add a returned car to the available-for-rent list,
3. add a returned car to the repair list,
4. transfer a car from the repair list to the available-for-rent list,
5. rent the first available car,
6. print all the lists,
7. quit.
6
Printing all lists
Available:
License: AAAA110, Mileage: 1000km.
License: AAAA111, Mileage: 1001km.
License: AAAA112, Mileage: 1002km.
License: AAAA113, Mileage: 1003km.
License: AAAA114, Mileage: 1004km.
Rented:
License: AAAA115, Mileage: 1005km, Return Date: 140101.
License: AAAA116, Mileage: 1006km, Return Date: 140102.
License: AAAA118, Mileage: 1008km, Return Date: 140104.
License: AAAA119, Mileage: 1009km, Return Date: 140105.
In repair:
License: AAAA120, Mileage: 1010km.
License: AAAA121, Mileage: 1011km.
License: AAAA122, Mileage: 1012km.
License: AAAA123, Mileage: 1013km.
License: AAAA124, Mileage: 1014km.
1. add a new car to the available-for-rent list,
2. add a returned car to the available-for-rent list,
3. add a returned car to the repair list,
4. transfer a car from the repair list to the available-for-rent list,
5. rent the first available car,
6. print all the lists,
7. quit.
1
Adding new car to available for-rent list
Please enter a license plate (AAAA111), and a mileage (1001) individually:
ABCD123
1013
Added new car to available list
1. add a new car to the available-for-rent list,
2. add a returned car to the available-for-rent list,
3. add a returned car to the repair list,
4. transfer a car from the repair list to the available-for-rent list,
5. rent the first available car,
6. print all the lists,
7. quit.
2
Adding returned car to available for-rent list
Please enter a license plate (AAAA111), and a mileage (1001) individually:
AAAA117
1007
Could not find the car you entered
1. add a new car to the available-for-rent list,
2. add a returned car to the available-for-rent list,
3. add a returned car to the repair list,
4. transfer a car from the repair list to the available-for-rent list,
5. rent the first available car,
6. print all the lists,
7. quit.
2  
Adding returned car to available for-rent list
Please enter a license plate (AAAA111), and a mileage (1001) individually:
AAAA118
1008
Found the car you entered
Removed from the rented list
Added to available list
Profit of transaction: $176.20
1. add a new car to the available-for-rent list,
2. add a returned car to the available-for-rent list,
3. add a returned car to the repair list,
4. transfer a car from the repair list to the available-for-rent list,
5. rent the first available car,
6. print all the lists,
7. quit.
5
Renting first available car
Enter a return date (YYMMDD)
140206
Car Rented
1. add a new car to the available-for-rent list,
2. add a returned car to the available-for-rent list,
3. add a returned car to the repair list,
4. transfer a car from the repair list to the available-for-rent list,
5. rent the first available car,
6. print all the lists,
7. quit.
6
Printing all lists
Available:
License: AAAA111, Mileage: 1001km.
License: AAAA112, Mileage: 1002km.
License: AAAA113, Mileage: 1003km.
License: AAAA114, Mileage: 1004km.
License: AAAA118, Mileage: 1008km.
License: ABCD123, Mileage: 1013km.
Rented:
License: AAAA115, Mileage: 1005km, Return Date: 140101.
License: AAAA116, Mileage: 1006km, Return Date: 140102.
License: AAAA119, Mileage: 1009km, Return Date: 140105.
License: AAAA110, Mileage: 1000km, Return Date: 140206.
In repair:
License: AAAA120, Mileage: 1010km.
License: AAAA121, Mileage: 1011km.
License: AAAA122, Mileage: 1012km.
License: AAAA123, Mileage: 1013km.
License: AAAA124, Mileage: 1014km.
1. add a new car to the available-for-rent list,
2. add a returned car to the available-for-rent list,
3. add a returned car to the repair list,
4. transfer a car from the repair list to the available-for-rent list,
5. rent the first available car,
6. print all the lists,
7. quit.
7
Quitting
Total Income: $176.20

Q2 HOW TO:
To run the postfix operations program, type "./bin/q2 " followed by a postfix expression, i.e. 12+43-*
The program pushes the numbers in a stack and when it encounters an operation it pops, evaluating the expression.

Q2 SAMPLE:
./bin/q2 45+93-*
45+93-* is equal to 54.
