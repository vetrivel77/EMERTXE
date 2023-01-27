/*
NAME : VETRIVEL P
DATE : 31/12/2022
DESCRIPTION : A06 - WAP to avoid child becoming zombie without blocking parent
SAMPLE I/P AND O/P:
Pre-requisites:

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about processes & zombie process.
Working of fork & wait system call.
Objective:

To understand different states of a process.

Requirements: 

Create a child process avoid it become a zombie.
To avoid zombie we need to call wait(), but this block parent until child terminates.
So we need to use waitpid() with proper arguments (Read man page). 
When child is working parent has to continuously print some message.
When ever child terminates parent has to print child terminated and print exit status of child process
Sample execution:
./nonblock_wait
A child created with pid 1234
parent is running
parent is running
parent is running . .
............................
Child 1234 terminated normally with exit status 0 parent terminating
*/

#include "main.h"

int main()
{
    //varible declartion
    pid_t pid;
    int wstatus;

    //To creat a new process
    pid = fork();
    
    //To check pid values using conditional statement
    //parent part
    if(pid > 0)
    {
        printf("A child created with pid %d\n",getpid());
        //using wait system call to run the parent till child execute
        while(waitpid(pid, &wstatus, WNOHANG) == 0)
        {
            printf("Parent is Running\n");
        }
    }
    //Child part
    else if(pid == 0)
    {
        //sleep to 2-sec then child is get terminated
        sleep(2);
        printf("Child %d terminated normally with exit status %d parent terminating\n",getpid(),pid);
    }
    else
    {
        //fork error check
        perror("Fork");
        exit(0);
    }
    return 0;
}
