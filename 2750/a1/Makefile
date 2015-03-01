CC=gcc
CFLAGS=-g
FLAGS=-Wall
INCLUDES=$(addprefix -I,$(shell find . -not -iwholename "*.git*" -type d -print))
LDPATHS=$(addprefix -L,$(shell find . -not -iwholename "*.git*" -type d -print))
LDLIBS=-lpm
LDFLAGS=$(LDPATHS) $(LDLIBS)
PROGNAME=./a1test

all: build ParameterManager

build: a1test.c
	$(CC) $(CFLAGS) $(INCLUDES) a1test.c $(LDFLAGS) -o $(PROGNAME)

test: build
	$(PROGNAME)

ParameterManager: ParameterManager.o ParameterList.o List.o
	ar rcs libpm.a ParameterManager.o ParameterList.o List.o

#library objects
ParameterManager.o: ParameterManager.c ParameterManager.h ParameterList.c ParameterList.h List.c List.h Boolean.h
	gcc -c $(FLAGS) ParameterManager.c
ParameterList.o: ParameterList.c ParameterList.h List.c List.h
	gcc -c $(FLAGS) ParameterList.c
List.o: List.c List.h
	gcc -c $(FLAGS) List.c
