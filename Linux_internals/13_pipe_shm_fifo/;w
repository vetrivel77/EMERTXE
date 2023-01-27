#include "main.h"

#define SMSIZE 100
int main()
{
    //variable declaration
    int shmid,shmid1,len,i,fd;
    char str[100],str1[100],str2[100];
    void *shm,*shm1;
    key_t key,key1;
    
    //SHARED MEMORY
    //key can be read/write
    key = 'A';

    //create a chared memory 
    shmid = shmget(key, SMSIZE,IPC_CREAT | 0664);

    if(shmid < 0)
    {
        perror("shmget");
        exit(1);
    }
    //attach the shared memory    
    shm = shmat(shmid,NULL,0);
    if(shm < 0)
    {
        perror("shmat");
        exit(1);
    }
    else
    {
        printf("Received the string successfully\n");
        
        //varible declartion
        char *begin_ptr,*end_ptr,ch;
        
        //find the string length
        len = strlen(shm);

        //to start the string
        begin_ptr = shm;

        //end of the string
        end_ptr = shm + len - 1;

        //reverse string condtion
        for(i = 0 ; i < (len - 1)/2 ; i++)
        {
            ch = *end_ptr;
            *end_ptr = *begin_ptr;
            *begin_ptr = ch;

            //update pointer to position
            begin_ptr++;
            end_ptr--;
        }         
        printf("Reverse the string value = %s\n",(char*)shm);
        strcpy(str2,shm);
    }      
    //FIFO PROCESS
    //USING FIFO STRING VALUE SEND TO THE SENDER
    mkfifo(FIFO_NAME,0666);

    //open the file in write mode
    fd = open(FIFO_NAME,O_WRONLY);
    if(fd < 0)
    {
        perror("open\n");
        exit(1);
    }
    else
    {
        //send the value 
        write(fd,&str2,sizeof(str2));
        printf("Write operation to FIFO is a completed\n");
        close(fd);
        exit(1);
    }
    return 0;    
}

