/*
NAME: VETRIVEL P
DATE: 30/12/2022
DESCRIPTION: A03 - WAP to understand usage of dup and dup2 system calls
SAMPLE I/P AND O/P:
Pre-requisites:

Knowledge about system calls, How to read and understand ‘man pages’.
Command line arguments, File operation system calls (open, read, write, close ..etc)
Working of dup system calls.
Objective:
To understand and implement using basic system calls.

Requirements:

Using dup or dup2 redirect printf out to a given file instead of printing to stdout.
Pass the file name using command-line arguments.
Try using both system calls (dup and dup2).
Sample Execution:
./dup_dup2 f1.txt
Print this message into STDOUT

Note : printf() should be diverted on file and one on STDOUT
*/

#include "main.h"

int main(int argc,char *argv[])
{
    //variable declaration
    int option;
    
    //validation
    if(argc < 2)
    {
        printf("Please pass valid command line aruments\n");
        return -1;
    }
    //display the menu
    printf("Menu : \n1.dup\n2.dup2\n");

    //read option from user
    printf("choose the option : ");
    scanf("%d",&option);
    
    //dup contions
    if(option == 1)
    {  
        //file operation write only mode 
        // To redirect message into file.txt      
        int fd1 = open(argv[1],O_WRONLY);
        if(fd1 == -1)
        {
            perror("open");
            return -1;
        }
        int std_cpy = dup(1);
        close(1);

        int new_fd = dup(fd1);
        printf("dup->Print this message into FILE1\n");
        close(new_fd);
        
        //to print the message in STDOUT
        int n_fd = dup(std_cpy);
        printf("dup->Print this message into STDOUT1\n");
        close(n_fd);
    }
    //dup2 contions
    else if(option == 2)
    {
        //varible declaration  
        int std_cpy;

        //file operation write only mode 
        // To redirect nessage into file.txt                      
        int fd2 = open(argv[1],O_WRONLY);       
        if(fd2 == -1)
        {
            perror("open");
            return -1;
        }
        dup2(std_cpy,1);
        close(1);

        int new_fd = dup2(fd2,1);
        printf("dup2->Print this message into FILE2\n");
        close(fd2);

        //to print the message in STDOUT
        int m_fd = dup2(std_cpy,1);
        printf("dup2->Print this message into STDOUT2\n");
        close(m_fd);
    }
    return 0;
}
