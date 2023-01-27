/*
NAME : VETRIVEL P
DATE : 4/1/2023
DESCRIPTION : A07 - WAP to create child process to execute command passed through command line
SAMPLE I/P AND O/P:
Pre-requisites:-

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about processes.
Working of fork, wait and exec system calls.
Objective:

• To understand how to use exec system calls.

Requirements:

Create child and execute a command passed from command-line arguments.
If no arguments passed print a usage message.
In case any wrong command passed, print an error message.
After child terminates print the exit status of child process.
Sample execution: -
1. No args passed (Print usage info)
./exe_child Usage: ./exe_child args...
2. Valid arg. passed
./exe_child date
This is the CHILD process, with id 11612
Wed Apr  4 13:27:19 IST 2012
Child exited with status 0
*/

#include "main.h"
int main(int argc, char *argv[])
{
    //varible declartion
    pid_t pid;

    char *command[argc];
    int i;

    //cla validation part
    if(argc < 2)
    {
        printf("please pass valid argument\n");
        printf("Insuficient arguments\n");
        exit(1);
    }
    //condtion of additional one option added in cla
    for(i = 0 ; i < argc - 1 ;i++)
    {
        command[i] = argv[i+1];
    }
    command[i] = NULL;
    
    //creat a new process
    pid = fork();

    //parent process
    if(pid > 0)
    {
        //varible declartion			
        int status;			
        int wpid = wait(&status);
			
        //check exit status of child			
        if(WIFEXITED(status))			
        {                
            printf("child terminated normally\n");			
            printf("Child exited with status -> %d \n", WEXITSTATUS(status));			
        }			
        else			
        {				
            printf("Child terminated abnormally \n");				               
            printf("Child exited with code %d \n",WEXITSTATUS(status));			
        }
    }
    //child process
    else if(pid == 0)
    {
        printf("This is the child process, with id %d\n",getpid()); 
        sleep(2);
        //exec        
        if(execvp(argv[1], command) < 0)              
        {                  
            perror(command[0]);                
            exit(1);             
        }   
    }
    else
    {    
        perror("fork");
        exit(1);
    }
    return 0;
}
