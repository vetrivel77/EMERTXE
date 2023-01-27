/*
NAME : VETRIVEL P
DATE : 4/1/2023
DESCRPTION: A08 - WAP to create three child from the same parent
SAMPLE I/P AND O/P:
Pre-requisites:

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about processes.
Working of fork & wait system calls.
Objective:

• To understand how to use fork system calls.

 Requirements:

Create three child process from same parent.
Parent has to wait for all three child process.
Print exit status of each child when they terminates.
Sample execution:

./three_child

Child 1 with pid 2020 created
Child 2 with pid 2021 created
Child 3 with pid 2022 created
Child 2020 is terminated with code 0
Child 2021 is terminated with code 0
Child 2022 is terminated with code 0
*/

#include "main.h"

int main()
{
    //creat a new process
    int c1 = fork();

    //parents part
    if(c1 > 0)
    {               
        int c2 = fork();
        if(c2 > 0)
        {
            int c3 = fork();
            if(c3 > 0)
            {
                //child created message 
                sleep(2);
                printf("child 1 with pid %d created\n",c1);
                printf("child 2 with pid %d created\n",c2);
                printf("child 3 with pid %d created\n",c3);
                sleep(2);
            }
            //child process      
            else
            {                
                sleep(4);
                printf("child 3 pid %d was terminated with code %d\n",getpid(),c3);
            }
        }
        else
        {
            sleep(3);       
            printf("child 2 pid %d was terminated with code %d\n",getpid(),c2);

        }
        
    }
    else
    {
        sleep(2);
        printf("child 1 pid %d was terminated with code %d\n",getpid(),c1);
    }
    return 0;
}
