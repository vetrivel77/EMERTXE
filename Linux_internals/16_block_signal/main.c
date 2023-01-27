/*
NAME : VETRIVEL P
DATE : 15/01/2023
DESCRIPTION: A16 - WAP to block certain signals from being received from command line.
SAMPLE I/P AND O/P:
Pre-requisites:

• Knowledge about system calls, How to read and understand ‘man pages’.
• Good knowledge about signals and signal handling.
 • Working of sigaction system call and signal masking.
Objective:

 To understand importance of signal masking.
Requirements:

1. Write a signal handler function for any signal, say SIGINT .
2. While its running inside handler (use loop) block other signals(atleast 3) being received .
3. Use sa_mask from struct sigaction to set signals to be blocked (Refer man ).
4. To create a signal set use variable of sigset_t.
5. To add or remove signals from set use sigaddset, sigdelset functions (refer man).
6. Process will receive blocked signals once its out from handler. ﻿

Sample execution:

 1. ./block_signal
      Process 2345 waiting for signal.. press ctrl + c from terminal.
      SIGINT received
Inside handler
Inside handler
. .
.....

2. Now open another terminal and send signal to process using kill command.
Bash$ kill ­SIGUSR1 2345
Bash$ kill ­SIGTERM 2345
Bash$ kill ­SIGABRT 2345

3. After exiting from handler will respond to blocked signal.
*/

#include<stdio.h>
#include <signal.h>
#include<string.h>
#include<unistd.h>

void mysig_handler(int signum, siginfo_t *siginfo, void *data)
{
    sleep(2);
    printf("signal number -> %d\n",signum);
    for(int i = 0 ; i < 5 ;i++)
    {
        printf("In handler Running...\n");
        sleep(2);
    }
    sleep(2);
}
int main()
{
    //varible declaration
    struct sigaction newact;
    sigset_t set;

    newact.sa_flags = SA_SIGINFO;
        
    //clear memory
    memset(&newact, 0, sizeof(newact));
    newact.sa_sigaction = mysig_handler;
    
    //intialize the signal set
    sigemptyset(&set);
    //add the signal
    sigaddset(&set, SIGTERM);   

    //assign a signal
    newact.sa_mask = set;

    printf("Process %d waiting for signal.. press ctr + c from terminal\n",getpid());

    //register the sihgnal handler for SIGINT signal 
    sigaction(SIGINT, &newact, NULL); 
    sigaction(SIGUSR1, &newact, NULL);   
    sigaction(SIGSEGV, &newact, NULL);    
    sigaction(SIGCHLD, &newact, NULL);    
    
    while(1);
    
    return 0;
}

