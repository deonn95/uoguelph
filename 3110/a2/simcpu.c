#include "simcpu.h"
#define MAX 100

extern char ** getln();

int main(int argc, char * argv[]){
	
	int i, detailed = 0, verbose = 0, robin = 0, count = 0, processNum = 0, threadNum = 0, taskNum = 0, numProcesses = 0, tswitch, pswitch;
	int proc = 0, thr = 0, tak = 0;
	char ** args; 
	FILE * fin = freopen(argv[argc], "r", stdin);
	struct process * processes;
	
	if(fin == NULL){
		fprintf(stderr, "Error opening input file\n");
	}
	
	for(i = 0; i < argc; i++){
		if(strcmp("-d", argv[i]) == 0){
			if(!detailed)
				detailed = 1;
		}
		if(strcmp("-v", argv[i]) == 0){
			if(!verbose)
				verbose = 1;
		}
		if(strcmp("-r", argv[i]) == 0){
			if(!robin)
				robin = (int) strtol(argv[i + 1], NULL, 0);
		}
	}
	
	fprintf(stdout, "detailed: %d, verbose: %d, robin: %d\n", detailed, verbose, robin);
	
	args = getln();
	
	do{

		//if its the first line
		if(count == 0){
			numProcesses = atoi(args[0]);
			tswitch = atoi(args[1]);
			pswitch = atoi(args[2]);
		}
		//if its a process line
		else if(count == 1){
			processNum = atoi(args[0]) - 1;
			if(proc == 0){
				processes = P_create(numProcesses);
				proc = 1;
			}
			processes[processNum].numThreads = atoi(args[1]);
		}
		//if it's a thread num line
		else if(count == 2){
			threadNum = atoi(args[0]) - 1;
			if(thr == 0){
				processes[processNum].t = T_create(processes[processNum].numThreads);
				thr = 1;
			}
			processes[processNum].t[threadNum].arrtime = atoi(args[1]);
			processes[processNum].t[threadNum].numcpu = atoi(args[2]);
		}
		else if(count > 2){
			if(tak == 0){
				processes[processNum].t[threadNum].tasks = task_create(processes[processNum].t[threadNum].numcpu);
				tak = 1;
			}
			taskNum = atoi(args[0]) - 1;
			processes[processNum].t[threadNum].tasks[taskNum].cputime = atoi(args[1]);
			if(args[2] != NULL){
				processes[processNum].t[threadNum].tasks[taskNum].iotime = atoi(args[2]);
			}
			else{
				processes[processNum].t[threadNum].tasks[taskNum].iotime = 0;
			}
			
			if(taskNum + 1 == processes[processNum].t[threadNum].numcpu){
				tak = 0;
				count = 1;
				if(threadNum + 1 == processes[processNum].numThreads){
					thr = 0;
					count = 0;
				}
			}
		}
		//the last part of parsing a single thread
		count++;
		
		args = getln();
		
	}while(args[0] != NULL);
	
	int j, k;
	
	fprintf(stdout, "number of processes: %d, thread switch: %d, process switch: %d\n", numProcesses, tswitch, pswitch);
	for(i = 0; i < numProcesses; i++){
		fprintf(stdout, "process number: %d, number of threads: %d\n", i + 1, processes[i].numThreads);
		for(j = 0; j < processes[i].numThreads; j++){
			fprintf(stdout, "thread number: %d, arrival time: %d, number of CPUs: %d\n", j + 1, processes[i].t[j].arrtime, processes[i].t[j].numcpu);
			for(k = 0; k < processes[i].t[j].numcpu; k++){
				fprintf(stdout, "task number: %d, cpu time: %d, io time: %d\n", k + 1, processes[i].t[j].tasks[k].cputime, processes[i].t[j].tasks[k].iotime);
			}
		}
	}
	
	return 0;
	
}

struct task * task_create(int size){
	
	struct task * t = malloc(sizeof(struct task) * size);
	return t;
}

struct thread * T_create(int size){
	
	struct thread * t = malloc(sizeof(struct thread) * size);
	return t;
}

struct process * P_create(int size){
	
	struct process * p = malloc(sizeof(struct process) * size);
	return p;
}

/*****************************************
 * Priority Queue code obtained from http://www.sanfoundry.com/c-program-priority-queue/
 * Full credit goes to Manish Bhojasia
 * I made slight modifications to use it here.
 */

/* Function to create an empty priority queue */
struct queue * Q_create(int size, int tswitch, int pswitch)
{
	struct queue * q = malloc(sizeof(struct queue));
    q->front = q->rear = -1;
    q->tswitch = tswitch;
    q->pswitch = pswitch;
    q->numProcesses = size;
    return q;
}
 
/* Function to insert value into priority queue */
void insert_by_priority(struct queue * q,  int data)
{
    if (q->rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((q->front == -1) && (q->rear == -1))
    {
        q->front++;
        q->rear++;
        q->rear = data;
        return;
    }    
    else
        //check(q, data);
    q->rear++;
}
/*
Function to check priority and place element 
void check(struct queue * q, struct process * p)
{
    int i,j;
 
    for (i = 0; i <= q->rear; i++)
    {
        if (data >= q->processes[i])
        {
            for (j = q->rear + 1; j > i; j--)
            {
                q->processes[j] = q->processes[j - 1];
            }
            q->processes[i] = data;
            return;
        }
    }
    q->processes[i] = data;
}
 
Function to delete an element from queue 
void delete_by_priority(struct queue * q, int data)
{
    int i;
 
    if ((q->front==-1) && (q->rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= q->rear; i++)
    {
        if (data == q->processes[i])
        {
            for (; i < q->rear; i++)
            {
                q->processes[i] = q->processes[i + 1];
            }
 
        q->processes[i] = -99;
        q->rear--;
 
        if (q->rear == -1) 
            q->front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
 
Function to display queue elements 
void display_pqueue(struct queue * q)
{
    if ((q->front == -1) && (q->rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; q->front <= q->rear; q->front++)
    {
        printf(" %d ", q->processes[q->front]);
    }
 
    q->front = 0;
}
*/
