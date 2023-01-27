/*
NAME : VETRIVEL P
DATE : 15/01/2023
DESCRIPTION : A14 - WAP to print the address which is causing Segmentation fault
SAMPLE I/P AND O/P:
Pre-requisites:

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about signals and signal handling.
Working of sigaction system calls. 
Objective: 

• To understand working of signal handling. 

Requirements: 

Write a signal handler function to print address which caused seg-fault(SIGSEGV). 
Use sigaction system call to register signal. 
Use struct siginfo from sa_sigaction to print address (Read man page). 
Create a segmentation fault from code. 
When error occurs program should print address and exit. 
Sample execution: 

 ./sigsegv 

Segmentation fault ..!! 

Address 0x123456 caused error
*/

#include<stdio.h>
#include <signal.h>
#include<string.h>
#include<unistd.h>

void new_handler(int signum, siginfo_t *siginfo, void *data)
{       
    printf("Segmentation fault..!\n");   
    printf("address %p caused error\n",siginfo->si_addr);
    signal(SIGSEGV,SIG_DFL);
}
int main()
{
    //varible declaration
    struct sigaction newact;
    char *str = "Emertxe";
    
    //clear the garbage values
    memset(&newact, 0, sizeof(newact));

    //using ths SA_SIGINFO flag
    newact.sa_sigaction = new_handler;
    newact.sa_flags = SA_SIGINFO;  

    //register the sihgnal handler for SIGINT signal 
    sigaction(SIGSEGV, &newact, NULL);    
    
    //segmentation fault accour
    *str = 'W'; 
    
    return 0;
}
