README

A4 exectution:
Run the program with no command arguments after compilation:
./bin/a4

		/********************\
		\*Welcome to the AVL*/
		/*     Creator      *\
		\*                  */
		/*Deon  Naltchadjian*\
		\*     0832759      */
		/********************\

1. Initialization
2. Find
3. Insert
4. Remove
5. Check Height and Size
6. Find All (above a given frequency)
7. Exit
avl/> 

It will produce this.

User entry:
	
	Input 1:
	
avl/> 1
filename: A4.dat

This creates a tree with the keys in the file

	Input 2:
	
avl/> 2
find key: wrn99
key: wrn99, frequency: 306

finds the specified node + key

OR

avl/> 2
find key: bobsDogs
no_such_key

cannot find the key

	Input 3:
	
avl/> 3
insert key: wrn99
key: wrn99, frequency: 307

updates frequency + 1

OR

avl/> 3
insert key: bobsDogs
key: bobsDogs, frequency: 1

inserts a new node into the tree

	Input 4:
	
avl/> 4
remove key: wrn99
key: wrn99, frequency: 305

removes one from frequency

OR

avl/> 4
remove key: wrn94
key: wrn94, frequency: 0

removes it from tree entirely and reshapes it

OR

avl/> 4
remove key: bobsDogs
no_such_key
Segmentation fault (core dumped)

finds there is no key, but segfaults. I have no idea why.

OR

	Input 5:
	
avl/> 5
height: 12, size: 1483

gives the height and size of the tree

	Input 6:

avl/> 6
frequency: 1500
key: flr117, frequency: 7458
key: flr1453, frequency: 3085
key: flr1657, frequency: 1510
key: flr1662, frequency: 2471
key: flr1854, frequency: 2063
key: flr1857, frequency: 3072
key: flr1937, frequency: 1763
key: flr1971, frequency: 2702
key: flr2255, frequency: 3645
key: flr2910, frequency: 9790
key: flr2941, frequency: 1724
key: flr548, frequency: 1709
key: flr549, frequency: 5590
key: wrn104, frequency: 2715
key: wrn202, frequency: 2221
key: wrn203, frequency: 2119
key: wrn312, frequency: 1571

Gives all keys above frequency

	Input 7:
	
avl/> 7
exiting

Exits. Thaaaaaat's about everything.
