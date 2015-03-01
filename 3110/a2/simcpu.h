#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct queue * Q_create(int size, int tswitch, int pswitch);
void insert_by_priority(struct queue * q,  int data);
void check(struct queue * q, int data);
void delete_by_priority(struct queue * q, int data);
void display_pqueue(struct queue * q);
struct thread * T_create(int size);
struct process * P_create(int size);
struct task * task_create(int size);

struct task{
	
	int cputime;
	int iotime;
	
}task;

struct thread{
	
	int arrtime;
	int numcpu;
	struct task * tasks;
	
}thread;

struct process{
	
	int numThreads;
	struct thread * t; 
	
}process;

struct queue{
	
	int front;
	int rear;
	int tswitch;
	int pswitch;
	int numProcesses;
	struct process * processes;
	
}queue;

