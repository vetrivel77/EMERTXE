/*
NAME: VETRIVEL P
DATE: 8/01/2023
DESCRIPTION: A04 - WAP to understand advanced file control system calls
SAMPLE I/P AND O/P:
Pre-requisites:

Knowledge about system calls, How to read and understand ‘man pages’.
Command line arguments, File operation system calls (open, read, write, close ...etc)
Working of fcntl system calls.
Objective:

To understand and implement using advanced system calls.
Understand the need of file synchronization between processes.
Requirements:

Using fcntl system call synchronize a file between two processes (parent and child process).
Pass the file name using command-line arguments.
Before writing to file check file is locked, in case it is locked must wait the process until its unlocked.
If its unlocked, lock file and continue with writing.
Both process will do the same procedure.
Sample Execution:
1.When no arguments are passed
./a.out
Insufficient arguments
Usage:- ./a.out filename
2. ./a.out f1.txt
PARENT PROCESS: locked file
PARENT PROCESS: writing to file f1.txt
PARENT PROCESS: unlocked file
CHILD PROCESS: locked file
CHILD PROCESS: writing to file f1.txt
CHILD PROCESS: unlocked file

Note : Parent will perform some task Ex: Print prime numbers upto 15
Child may perform another task Ex : Print Fibonacci series upto 10
These things should be present in the file
*/
#include "main.h"

int main(int argc, char *argv[])
{
    //validation part
    if(argc < 2)
    {
        printf("please pass the valid cla aruguments\n");
        printf("insufficient arguments\n");
        exit(1);
    }
    int fd = open(argv[1],O_WRONLY);
    //close(1);
    if(fd == -1)
    {            
         perror("open");            
         exit(1);        
    }
    //varible declartion
    pid_t pid;
    struct flock file;
    
    //clear the memory
    memset(&file, 0, sizeof(file));

    //create a new process
    pid = fork();
    
    //parent process
    if(pid > 0)
    {
        sleep(2);
        printf("PARENT PROCESS: locked the file\n");
        //lock the file for writing            
        file.l_type = F_WRLCK;
        fcntl(fd, F_SETLKW, &file);
        printf("PARENT PROCESS: writing to file file.txt\n");                    
        printf("PARENT PROCESS: unlocked the file\n");
        //dup2 condition
        int std_cpy;       
        dup2(std_cpy,1);         
        close(1);                  
        int new_fd = dup2(fd,1); 
        
        //varible declartion        
        int num=15,i,fact,j;
        printf("\n");
        
        //prime number condition
        printf("Prime Numbers are: \n");
        for(i = 1; i <= num; i++)
        {
            fact=0;            
            for(j = 1; j <= num; j++)
            {
                if(i % j == 0)
                {
                    fact++;
                }
            }
            if(fact == 2)
            {
                printf("%d ",i);
            }
           
        }
        printf("\n"); 
        close(fd);

        //UNLOCK THE FILE 
        file.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &file);
    }
    else if(pid == 0)
    {
        
        printf("CHILD PROCESS: locked the file\n");
        //lock the file for writing            
        file.l_type = F_WRLCK;
        fcntl(fd, F_SETLKW, &file);
        printf("CHILD PROCESS: writing to file file.txt\n");           
        printf("CHILD PROCESS: unlocked the file\n"); 
        //dup condition        
        int std_cpy;
        dup2(std_cpy,1);         
        close(1);
        int new_fd = dup2(fd,1); 
        
        //varible declaration       
        int num=15,f1=0,f2=1,i;
        
        //fibonacci series condition
        if( num >= 0)
        {
            printf("fibonacci series are: \n");
            printf("%d %d",f1,f2);
            i = f1 + f2;
        }
        while(i <= num)
        {
            printf(" %d",i);
            f1 = f2;
            f2 = i;
            i = f1 + f2;
        }
        close(fd);
        //UNLOCK THE FILE 
        file.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &file);
    }
    else
    {
        perror("fork");
        exit(1);
    }
}
