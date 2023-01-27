/*
NAME : VETRIVEL P
DATE : 13/01/2023
DESCRIPTION : A09 - Implement communication between two related processes using one pipe
SAMPLE I/P AND O/P:
Pre-requisites:-

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about processes and IPC.
Working of pipe & dup system calls.
Objective:
• To understand working of pipe between two process.

Requirements:

Create two child process and execute commands passed from command-line arguments
Each command is separated by a '|' (pipe) character.
First child execute first command (with or without options) and pass o/p to next.
Second child executes second command (after '|') will reads I/p from first cmd.
Parent will wait for both child process to finish .
Sample execution:

./pipe (No arguments)
    Error: No arguments passed Usage: ./pipe   <command1 > '|'   <command2>

2. ./pipe ls

    Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2>

3. ./pipe ls '|' wc

    5 25 4.

4. ./pipe ls ­ -l -­a '|' wc -­l ­-w

    10 15
*/

#include "main.h"

int main(int argc, char *argv[])
{
    //varible declaration
    int pos,i;
    
    //cla validation part
    if(argc < 3)
    {
        printf("Plese pass valid command line arguments\n");
        printf("Insufficient commands\n");
        exit(1);
    }    
    //to check in cla | passed or not           
    else if((strcmp(argv[2],"|"))  == 0)             
    {          
            
        // file descripters 
        int fd[2]; //f[0]->read f[1]->write 

        //create a new pipe
        if( pipe(fd)== -1)
        {
            perror("pipe");
            exit(1);
        }
        //create a new process
        int pid1 = fork();
        int pid2 = fork();
           
        //parent process
        if(pid2 > 0)
        {
             sleep(4);
             exit(1);
        }
        //child1
        else if(pid1 == 0)
        {
            //child 1 argv[1]
            dup2(fd[1] , 1);
            close(fd[0]);
            close(fd[1]);
            execlp(argv[1],argv[1],(char*)NULL);
        }  
        //child2  
        else if(pid2 == 0)
        {        
            //child 2 argv[3] 
            dup2(fd[0] , 0);
            close(fd[0]);
            close(fd[1]);
            execlp(argv[3],argv[3],(char*)NULL);
        }          

    }
    else
    {            
        printf("Error : Insufficient arguments passed Usage:\n./pipe <command1> '|' <command2>\n");
        exit(1);
    }
    return 0;
}
