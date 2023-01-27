/*
NAME : VETRIVEL P
DATE : 14/01/2022
DESCRIPTION: A12 - Implement communication between two different processes using SHM
SAMPLE I/P AND O/P:
Pre-requisites:-

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about Shared memory
Objective:
To understand how to establish communication between 2 different process.
Requirements:

Create 2 different process by executing 2 different a.out (executable) file’s
Create SHM from any of the process. Either Process 1 or Process 2
In process 1
Prompt the user to enter a string
Convert the string into Upper case
Write the Upper case string  in shared memory
4.In process 2

Read the data from the shared memory
Reverse input which is read from SHM
Write the Reverse string  in shared memory
5.Read the data from shared memory in process 1
6.Print the output string on stdout
Sample output :

Run the two process executable in two different tabs

1. ./Process1

Enter the string: Hello

Writing to shared memory ......

Reading from shared memory:  OLLEH

2. ./Process 2

Reading from shared memory :olleh

Writing to Shared memory ...
*/

#include "main.h"

int main()
{
    //variable declaration
    int shmid,shmid1,i,len;
    char str[100];
    void *shm,*shm1;
    key_t key,key1;

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

        //read string from user
        printf("Enter the string : ");
        scanf("%s",str);

        //to change string lower case to upper case letter
        for(i = 0 ; str[i] != '\0' ; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
        }
        printf("Send the string to Receiver...successfully = %s\n",str);
        //write into shared memory
        strcpy(shm,str);
    }  
    sleep(5);
    //key can be read/write
    key1 = 'B';

    //create a chared memory
    shmid1 = shmget(key1, SMSIZE,IPC_CREAT | 0666);

    if(shmid1 < 0)
    {
        perror("shmget");
        exit(1);
    }
    //attach the shared memory
    shm1 = shmat(shmid1,NULL,0);
    if(shm1 < 0)
    {
        perror("shmat");
        exit(1);
    }
    else
    {         
        printf("Received the Reverse string value from receiver..successfully\n");
        printf("%s\n",(char*)shm1);
    }
    return 0;
}
