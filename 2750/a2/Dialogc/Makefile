CFLAGS=-Wall
INCLUDE=/usr/lib/jvm/java-1.7.0-openjdk-amd64/include -I/usr/lib/jvm/java-1.7.0-openjdk-amd64/include/linux

all: libpm.so
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.
	
#crate the shared library
libpm.so: JNIlib.o ParameterManager.o Dialogc
	gcc -shared -I$(INCLUDE) -o libpm.so JNIlib.o ParameterManager.o

#create the necessary files for parameterManager 
ParameterManager.o: ParameterManager.c ParameterManager.h ParameterList.c ParameterList.h List.c List.h Boolean.h
	gcc -c -fPIC $(CFLAGS) ParameterManager.c
ParameterList.o: ParameterList.c ParameterList.h List.c List.h
	gcc -c -fPIC $(CFLAGS) ParameterList.c
List.o: List.c List.h
	gcc -c -fPIC $(CFLAGS) List.c

#create the object file used for shared library
JNIlib.o: JNIlib.c JNIlib.h
	gcc -c -fPIC $(CFLAGS) -I$(INCLUDE) JNIlib.c
#create the JNIlib.class file
JNIlib: JNIlib.java
	javac JNIlib.java
#create the automated JNIlib header file
JNIlib.h: JNIlib
	javah -jni JNIlib

#create the Dialogc.class file, THE EXECUTABLE
Dialogc: Dialogc.java
	javac Dialogc.java
