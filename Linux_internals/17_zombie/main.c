/*
NAME : VETRIVEL P
DATE : 19/1/2023
DESCRIPTION	: Program to avoid child become zombie using signal handler
SAMPLE I/OAND O/P:
1. ./avoid_zombie 
child  terminated with exit code 0.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
void handler(int signum,siginfo_t *info, void *data)
{
    printf("This is a parent process\n");
    printf("Child %d terminated with exit code %d \n",info->si_pid,info->si_status);
    exit(1);
}
int main()
{

    struct sigaction act;
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO | SA_NOCLDWAIT; // SA_NOCLDWAIT for avid child from zombie
    pid_t pid;
    int status;
    sigaction(SIGCHLD,&act,NULL); // sigaction registration
    pid =fork();  // childprocess creation
    if(pid < 0) 
    {
        printf("Error : fork() failed");
        return 1;
    }
    else if(pid == 0) // it's child
    {
        sleep(1);
        exit(0);
    }
    else  // it's parent
    {       
        sleep(4);
        exit(0);
    }
    return 0;
}

