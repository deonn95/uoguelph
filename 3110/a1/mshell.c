/*********************************
 * Deon Naltchadjian 0832759
 * Jan 30 2015
 * CIS 3110 A1
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

extern char **getln();

int main(){
	
	int i, j, status;
	char **args, ** modified; 
	int argc = 0;
	int num, sum, err, in, out, waiting;
	char * cat;
	pid_t pid; 
	FILE * fout, * fin;
	
	printf("Welcome to dnSHELL! Enter one of the following:\n");
	printf("1. \"exit\"\n");
	printf("2. a command with no arguments (i.e. \"ls\")\n");
	printf("3. a command with arguments (i.e. \"ls -l\")\n");
	printf("4. a command with or w/o arguments using & (i.e. \"xemacs &\")\n");
	printf("5. a command with or w/o arguments using > (i.e. \"ls -l > foo\")\n");
	printf("6. a command with or w/o arguments using < (i.e. \"sort < testfile\")\n");
	printf("7. a command with or w/o arguments using | (i.e. \"ls -l | more\")\n");
	printf("8. \"add\": takes in arguments and adds them (i.e. \"add 100 210 0xa\")\n");
	printf("9. \"args\": takes in arguments and counts, lists (i.e. \"args 1 2 3 foo\")\n");
	printf("10. \"concat\": concats arguments into single, spaceless string (i.e. \"cat hello world\")\n");
	
	while(1) {
		
		printf("dnSHELL> ");
	
		args = getln();
		
		num = 0;
		sum = 0;
		err = 0;
		in = 0;
		out = 0;
		waiting = 0;
		j = 0;
		
		modified = (char **) malloc(sizeof(char * ) * 100);
		
		for(i = 0; args[i] != NULL; i++){
			if(args[i + 1] == NULL)
				argc = i;
		}
		/*exit the program*/
		if(strcmp("exit", args[0]) == 0){
			exit(0);
		}
		/*count and list arguments*/
		else if(strcmp("args", args[0]) == 0){
			printf("argc: %d, args: ", argc);
			for(i = 1; i <= argc; i++){
				printf("%s", args[i]);
				if(i < argc){
					printf(", ");
				}
			}
			printf("\n");
		}
		/*add args, convert from hex if necessary*/
		else if(strcmp("add", args[0]) == 0){
			for(i = 1; i <= argc; i++){
				printf("%s", args[i]);
				if(i < argc){
					printf(" + ");
				}
				num = (int) strtol(args[i], NULL, 0);
				sum += num;
			}
			printf(" = %d\n", sum);
		}
		/*concatenates the arguments into a single string*/
		else if(strcmp("concat", args[0]) == 0){
			for(i = 1; i <= argc; i++){
				num = strlen(args[i]);
				sum += num;
			}
			cat = malloc(sizeof(char) * sum + 1);
			for(i = 1; i <= argc; i++){
				strcat(cat, args[i]);
			}
			printf("concatenated: %s\n", cat);
			free(cat);
		}
		/*any other commands*/
		else{
			if(strcmp(args[argc], "&") != 0){
				waiting = 1;
			}
			
			for(i = 0; i <= argc; i++){
				/*if its output or input is redirected*/
				if(strcmp(args[i], ">") == 0){
					fout = freopen(args[i + 1], "w", stdout);
					out = 1;
					i++;
				}
				else if(strcmp(args[i], "<") == 0){
					fin = freopen(args[i + 1], "r", stdin);
					in = 1;
					i++;
				}
				else if(strcmp(args[i], "&") == 0){
				/*used as continue*/
				}
				else if(strcmp(args[i], "|") == 0){
				/*used as continue, gotta pipe here*/
					
				}
				else{
					modified[j] = args[i];
					j++;
				}
			}
			pid = fork();
			if(pid < 0){
				printf("Error creating child process\n");
			}
			else if(pid == 0){
				err = execvp(args[0], modified);
				exit(0);
				if(err >= 0){
					printf("Error executing process\n");
				}
			}
			else{
				if(waiting == 0){
					signal(SIGINT, SIG_IGN);
				}
				else{
					if(waitpid(pid, &status, 0) >= 0){
						if(status != 0){
							fprintf(stdout, "Error, child did not terminate correctly\n");
						}
					}
				}
			}
			if(out == 1){
				fclose(fout);
			}
			if(in == 1){
				fclose(fin);
			}
			free(modified);
		}
	}
	return 0;
}
