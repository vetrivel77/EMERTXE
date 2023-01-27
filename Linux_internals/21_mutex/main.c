/*
NAME		: VETRIVEL P
DATE		: 20/1/2023
DESCRIPTION	: WAP to sum and maximum of a given array using multiple threads.Synchronize threads using mutex.
SAMPLE I/O	:
1. ./sum_max
Enter the size of array : 100
max = 100 Sum = 1020


*/
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int sum, max;
int array[1000];
typedef struct // structure for start and end number
{
    int start;
    int end;
}st;
pthread_mutex_t lock;  
void * sum_max(void* param) // function to find maximum and sum of given number
{
    pthread_mutex_lock(&lock); // mutex lock
    st *info = param;
    int i;
    for(i = info->start; i <= info -> end; i++)
    {
	sum += array[i];
	if(max < array[i])
	    max = array[i];
    }
    pthread_mutex_unlock(&lock); // mutex unlock for a thread

}
int main()
{
    int num,i;
    static int j = 0;
    printf("Enter number : \n"); // read number from user
    scanf("%d",&num);
    for(i = 0; i < num; i++)  // store 1 to num to array
    {
	array[i] = i+1;
    }
    pthread_t td1,td2,td3,td4,td5; // 5 threads
    pthread_t *arr[5] = {&td1,&td2,&td3,&td4,&td5}; // adress of thread store in a array
    st td[5];
    int div = num / 5;
    for(i = 0; i<5 ; i++) // find start and end index value for each thread
    {
	    td[i].start = j;
	    td[i].end   = j + (div-1);
	    j+=div;
    }
    for(i = 0; i < 5 ; i++) // 5 thread created
    {
	pthread_create(arr[i],NULL,sum_max,&td[i]);
    }
    for(i=0; i<5; i++) // wait 5 thread till it complet execution
    {
	pthread_join(*arr[i],(void**)NULL);
    }
    printf("Max = %d Sum = %d\n",max,sum); // print output
    return 0;

}

