README

	This is the dnSHELL!
To compile my shell program, type "make". It should compile no problem.
To run my shell, type "./msh"
Once you open it, it gives a list of commands and you can type whichever ones
you want. I DO NOT have pipes working, and output redirection works but it segfaults.
Input redirection works, but the lex.c crashes after you redirect input for some reason, saying 
"input in flex scanner failed". The "&" works however ASSUMING it is the last argument, 
and will execute processes in the background.

	For my function I chose to do concatenation, where it takes in a bunch of
arguments and concatenates them, for example "concat foo bar hello world"
would output "concatenated: foobarhelloworld", effectively making them into one string.
I acknowledge the fact that one of my required functions does not work, my output redirection segfaults
but works, and my input redirection closes the shell, but I accept the penalty, roughly 25 to 30 marks
according to the marking scheme.

	To give credit where needed, I used the lex.c, flex compiler, mshell.c, and Makefile
provided by the TA's. The mshell.c I simply added to. My algorithm is simple, just check
for "args", "add", "concat", and "exit". All else results in a system call. If the call
doesn't exist, nothing happens.
