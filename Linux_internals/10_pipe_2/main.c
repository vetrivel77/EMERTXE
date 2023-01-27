/*
NAME: VETRIVEL P
DATE : 13/01/2023
DESCRIPTION: Implement communication between three related processes using two pipe
SAMPLE I/P AND O/P:
Pre-requisites:- 

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about processes and IPC. 
Working of pipe & dup system calls.
Objective: 
• To understand working of pipe between two process. 

Requirements: 

Create three child process and execute commands passed from command-line arguments 
Each command is separated by a '|' (pipe) character. 
First child execute first command (with or without options) and pass o/p to next. 
Second child executes second command (after '|') will reads I/p from first pipe. 
Third Child execute third command (after 2nd pipe '|') will read i/p from second pipe.
Parent will wait for  child process to finish .
Sample execution:

 ./three_pipes (No arguments)
 Error: No arguments passed Usage: ./three_pipes  <command1 > '|'   <command2> '|'  <command3 >       

2. ./pipe ls ­l '|' grep 

 Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2> '|'  <command3 >

3. ./pipe ls -­l '|' grep “pattern” '|' wc -­l 

5 5 25
*/

#include "main.h"

int main(int argc, char *argv[])
{
    //varible declation
    int pipe_fd[2];
	int pipe_fd1[2];
	int newfd,fd;
	pid_t pid_child1,pid_child2,pid_child3;
	int i=1,argc_1=0,argc_2=0,argc_3=0,j=0;
	/* check for argument validity */
	if(argc < 6)
	{
		printf("Insufficient arguments passed!\n");
		printf("Usage : ./pipe <command 1> '|' <command 2> '|' <command 3>\n");
    return 0;

	}
	/* get command 1 from cli */
	while(strcmp(argv[i++],"|")!=0)
		argc_1++;
	char *arg_1[argc_1+1];
	for(i=1;i<argc_1+1;i++)
	{
		arg_1[i-1]=argv[i];
	}
	arg_1[i-1]=NULL;

	/* get command 2 from cli */
	i=argc_1+2;
	while(strcmp(argv[i++],"|")!=0)
    {
		argc_2++;
    }
	char *arg_2[argc_2+1];
	for(i=argc_1+2;strcmp(argv[i],"|")!=0;i++)
	{
		arg_2[j]=argv[i];
		j++;
	}
	arg_2[j]=NULL;

	/* get command 3 from cli */
	i=argc_1+argc_2+3;
	while(argv[i++]!=NULL)
    {
		argc_3++;
    }
	char *arg_3[argc_3+1];
	j=0;
	for(i=argc_1+argc_2+3;i<argc;i++)
	{
		arg_3[j]=argv[i];
		j++;
	}
	arg_3[j]=NULL;

	/* create a pipe to communicate between related processes */
	pipe(pipe_fd);
	pipe(pipe_fd1);

	/* creating child 1 */
	pid_child1=fork();
	{
		switch(pid_child1)
		{
			/* failure */
			case -1:
				perror("fork");
				return 1;
				break;

				/* child 1 (command 1) */
			case 0:
				close(pipe_fd1[0]);
				close(pipe_fd1[1]);
				/* close read end of first pipe */
				close(pipe_fd[0]);
				/* closing stdout */
				close(1);
				/* duplicating fd to redirect stdout */
				newfd=dup(pipe_fd[1]);
				/* execute command 1*/
				execvp(arg_1[0],arg_1);
				perror("exec fail");
				return 1;

			default:
				/* creating child 2 */
				pid_child2=fork();

				switch(pid_child2)
				{
					/* failure */
					case -1:
						perror("fork");
						return 1;

						/* child 2 (command 2) */
					case 0:
						/* close write end */
						close(pipe_fd[1]);
						/* close stdin */
						close(0);
						/* duplicate fd to redirect stdin */
						newfd=dup(pipe_fd[0]);
						/* close read end of second pipe */
						close(pipe_fd1[0]);
						/* close stdout */
						close(1);
						/* duplicate fd to redirect stdout */
						newfd=dup(pipe_fd1[1]);
						/* execute command 2 */
						execvp(arg_2[0],arg_2);
						perror("exec fail");
						return 1;
						break;

						/* parent */
					default :
						/* close read and write end of first pipe */
						close(pipe_fd[0]);
						close(pipe_fd[1]);
						/* creating child 3 */
						pid_child3=fork();

						switch (pid_child3)
						{
							/* failure */
							case -1:
								perror("fork");
								return 1;

								/* child 3 (command 3) */
							case 0:
								/*close write end of second pipe */
								close(pipe_fd1[1]);
								close(0);
								newfd=dup(pipe_fd1[0]);
								execvp(arg_3[0],arg_3);
								perror("exec fail");
								return 1;
								break;
								/* parent */
							default:
								sleep(3);
						}		

                }		        
        
        }        	
    
    }

}


