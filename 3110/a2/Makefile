all: simcpu

simcpu: simcpu.o lex.yy.o
	gcc simcpu.o lex.yy.o -lfl -o simcpu
simcpu.o: simcpu.c simcpu.h
	gcc -Wall -g -c simcpu.c
lex.yy.o: lex.yy.c
	gcc -Wall -g -c lex.yy.c
lex.yy.c: lex.c
	flex lex.c
clean:
	rm -f *.o
	rm -f lex.yy.c
	rm -f msh
