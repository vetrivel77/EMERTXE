/*
NAME : VETRIVEL P
DATE : 01/01/2023
DESCRIPTION : A05 - WAP to make zombie process become orphan, print status of each state
SAMPLE I/P AND O/P:
Description :

Create a scenario to make zombie process become orphan, print status of each state.

Pre-requisites:

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about processes, zombie and orphan.
Working of fork system call.
Objective:

• To understand different states of a process.

Requirements: 

Create a child process and print status that process is running
After some time print status that process is zombie state
After some time print zombie process cleared by init.
To print status use help of /proc//status file.
For eg: if child pid is 1234, open file /proc/1234/status and print first 3 lines
      5. If that file is not available means that process is cleared.

Sample execution:

1. ./zomb_orph
A child created with pid 1234
Name:  ./zomb_orph
State: S (sleeping)
Name:  /zomb_orph   (After some time)
State: Z (zombie)
Process 1234 cleared by init  (After some time)
*/

#include "main.h"

int main()
{
    //varible declartion
    pid_t pid;

    //To creat new process
    pid = fork();

    //parent checking part
    if(pid > 0)
    {         
        sleep(2);
        //varible declartion
        char path[50];

        //get parent zombie child status and print the status
        sprintf(path, "cat /proc/%d/status | head -2",pid);
        printf("%s\n",path);

        //system call
        system(path);
        
        //to creat a new process 
        int pid1 = fork();
        
        if(pid1 > 0)
        {
            //print the init cleared message
            printf("Process %d cleared by init\n",pid);
            sleep(2);
            exit(1);
        }
        else if(pid1 == 0)
        {
            sleep(2);
            exit(1);           
        }

    }
    //child checking part
    else if(pid == 0)
    {
        //varible declaration
        char path[50];
        int ret = getpid();

        //print the child creating message with pid
        printf("Child created with pid %d\n",ret);

        //get child status ajnd print the details
        sprintf(path, "cat /proc/%d/status | head -3",ret);
        printf("%s\n",path);
        //system call
        system(path);
        exit(1);
    }
    //error checking part
    else
    {
        // fork error check
        perror("Fork");
        exit(1);
    }
    return 0;
}
