/*
NAME : VETRIVEL P
DATE : 14/02/2023
DESCRIPTION : A13 - Implement communication between three processes using PIPE, FIFO and SHM
SAMPLE I/P AND O/P:
Pre-requisites:-

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about Pipe ,FIFO and Shared memory
Objective:
To understand how to establish communication between 3 different process using 3 different IPC mechanism.
Requirements:

Create 2 different process by executing 2 different a.out (executable) file’s
Create a new process (child process) in Process 1
Create a Pipe between Parent and Child Process
Create SHM from any of the process. Either Process 1 or Process 2
In Parent Process 1
Prompt the user to enter a string
Write the string in pipe
Read the string from pipe into child process
Convert the string into Upper case
Write the Upper case string  in shared memory
6.In process 2

Read the data from the shared memory
Reverse input which is read from SHM
Write the Reverse string  in FIFO
7.Read the data from FIFO in Parent process 1
8.Print the output string on stdout
*/

#include "main.h"

int main()
{
    //varible declartion
    char str[100];
    char str1[100],str2[100];    
    int shmid,shmid1,i,len,fd;
    void *shm,*shm1;
    key_t key,key1;

    //file descripters
    int p[2];
     
    //create a new pipe        
    if( pipe(p)== -1)        
    {           
        perror("pipe");            
        exit(1);       
    }
    
    //new process creation
    int pid = fork();
    if(pid == -1)
    {
        perror("pid");
        exit(1);
    }
    //parent process
    if(pid > 0)
    {
        //PIPE PROCES
        sleep(1);
        close(p[0]);
        printf("Hii i am parent...\n");                                        
        printf("enter the string : ");
        scanf("%s",str);
        write(p[1],&str,sizeof(str));              
        close(p[1]);
    }
    //child process
    else if(pid == 0)
    {
        //PIPE PROCESS
        sleep(5);
        printf("Hii i am child...\n");
        close(p[1]);                           
        read(p[0],str1,sizeof(str1));         
        close(p[0]);
        
        //SHARED MEMRORY
        //stored the string value to shared memory
        //key can be read/write
        key = 'A';

        //create a shared memory
        shmid = shmget(key, SMSIZE,IPC_CREAT | 0664);

        if(shmid < 0)
        {
            perror("shmget");
            exit(1);
        }
        else
        {
            shm = shmat(shmid,NULL,0);
            //to change string lower case to upper case letter
            for(i = 0 ; str1[i] != '\0' ; i++)
            {
                if(str1[i] >= 'a' && str1[i] <= 'z')
                {
                    str1[i] = str1[i] - 32;
                }
            }   
            printf("Send the string to Receiver...successfully = %s\n",str1);
        }
        //write into shared memory
        strcpy(shm,str1);
    }
    //error checking
    else
    {
        perror("Fork");
        exit(1);
    }        
    //FIFO PROCESS        
    //RECEIVE THE FIFO STRING VALUE
                
    //open the file in read mode       
    fd = open(FIFO_NAME, O_RDONLY);
                
    if(fd < 0)        
    {           
        perror("open\n");            
        exit(1);       
    }        
    else        
    {          
        //receive the value            
        read(fd,&str2,sizeof(str2));           
        printf("FIFO MESSAGE RECEIVED : %s\n",str2);      
        close(fd);            
        exit(1);           
    }
    return 0;
}
