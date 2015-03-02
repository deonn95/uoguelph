README

Deon Naltchadjian
0832759
Due Sept 29 2014
Assignment 1

Program Execution

To execute the program, go to the root folder and type "./bin/a1", no command line arguments.
It will open a text menu with multiple single-character options allowing you to choose which of the three functions to run.

Carbon Program
To open the Carbon program on the menu, type 'c'. This function does not use recursion, although I tried to implement it at the bottom of the file
The recursive functions can be seen commented out at the bottom of carbon.c

Example run

Type 'c' to see the Carbon permutation function.
Type 'a' to see Ackermann's function.
Type 'n' for Newton's root function (RECURSIVE).
Type 'N' for Newton's root function (NON-RECURSIVE).
Type 'e' to exit.
c
carbon
carbno
carnob
carnbo
...
nobacr
nobarc
nobrca
nobrac

Ackermann Program
To open the Ackermann program on the menu, type 'a'. This function uses recursion. When using large numbers, this program takes a little while to
work. The example below takes about 10 seconds on an AMD Phenom A6 processor.

Sample run

Type 'c' to see the Carbon permutation function.
Type 'a' to see Ackermann's function.
Type 'n' for Newton's root function (RECURSIVE).
Type 'N' for Newton's root function (NON-RECURSIVE).
Type 'e' to exit.
a
Please enter two natural numbers:
4
1
A(4, 1) = 65533

Newton Program
To open the Newton program on the menu, type either 'n' for the Recursive function or 'N' for the non-recursive function.

Sample run (both recursive and non-recursive output the same)

Type 'c' to see the Carbon permutation function.
Type 'a' to see Ackermann's function.
Type 'n' for Newton's root function (RECURSIVE).
Type 'N' for Newton's root function (NON-RECURSIVE).
Type 'e' to exit.
n
Please enter the number you would like to see the root of
followed by the degree of accuracy:
40
0.001
Newton's root of 40.000000 with accuracy 0.001000: 6.324555

Exiting
To exit, type 'e'.
