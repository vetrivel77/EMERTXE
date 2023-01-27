#include "main.h"

#define SMSIZE 100
int main()
{
    //variable declaration
    int shmid,shmid1,len,i;
    char str[100],str1[100];
    void *shm,*shm1;
    key_t key,key1;

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
    }        
    printf("Reverse the string value = %s\n",(char*)shm);
    //key can be read/write
    key = 'B';

    //create a chared memory
    shmid1 = shmget(key, SMSIZE,IPC_CREAT | 0666);
    //shared memory copy into str     
    strcpy(str,shm);
     
    if(shmid1 < 0)
    {
        perror("shmget");        
        exit(1);
    }
    else
    {        
        printf("Reverse string value passed to sender..successfully\n");
        shm1 = shmat(shmid1,NULL,0);       
         
        //write into shared memory
        strcpy(shm1,str);
    }

}

