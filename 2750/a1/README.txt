README

THE LIBPM.A FILE GETS MADE BUT IT SAYS UNDEFINED REFERENCE TO MAIN.
*******************************************************************

I don't know why, I spent more time on the Makefile than imaginable, but it does NOT
compile correctly. I can't figure it out, looked at many tutorials but it just doesn't
work. It compiles if I put a main function but I know that isn;t the purpose of the
library. I understand the -c flags are supposed to make it so a main is not required
but apparently it doesn't with mine. 

*******************************************************************

To compile the library, type make, make all or make ParameterManager.
This should create the libpm.a file.

As far as I know, the parser has no errors but I could be wrong. (I did extensive testing and seemed to be fine).
In terms of memory leaks, I don't know if I have any as I haven't used valgrind with my program.
I'm fairly certain the destory functions work well enough, I tested them as much as I could.
