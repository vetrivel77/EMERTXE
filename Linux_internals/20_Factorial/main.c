/*
NAME		: VETRIVEL P
DATE		: 20/1/2023
DESCRIPTION	: Program to find factorial of a given number using multithread.
SAMPLE I/O	:
1. ./factorial 
Enter the number :10 
Factorial of 10 is 3628800


*/

#include<stdio.h>
#include<pthread.h>
    typedef struct  // structure for end and start value
    {
	int start;
	int end;
    }st;
void * fact(void* param)  // function for find intermidate factorial
{
    st* info = param;
    int i, result = 1,k = 0 ;
    printf("%d %d\n",info->start,info->end); // print start and end value for each thread
    if(info->start * info->end )
    {
    for(i = info->start; i <= info->end; i++ ) // if both number is non zero
    {
	result *= i;
    }
    }
    else if(info->end == 0 && info->start != 0) // if end value is 0
    {
	result = info ->start;
    }
    else
	result = 1;  // both are 0
    return (void*)(long)result;
}
int main()
{
    int num,i=0,j=0,div,k;
    pthread_t td1,td2,td3;
   pthread_t *arr[3] = {&td1,&td2,&td3}; // pointer array for thread
    int result[3];
    printf("Enter number : ");
    scanf("%d",&num);
    if(num < 0)  // if number is -ve
    {
	printf("Error : Enter positive number\n:");
	return 1;
    }
    st thread[3];  
    if( num == 0)  // find start and end number, if number = 0 , all start and end value = 0
    {
	for(i=0; i<3; i++)
	{
	    thread[i].start = 0;
	    thread[i].end = 0;
	}
    }
    else if (num < 3) // if number less than 3, 1st thread start value is num and remining value 0
    {
	thread[0].start = 1;
	thread[0].end = num;
	for(i=1; i< 3; i++)
	{
	    thread[i].start = 0;
	    thread[i].end = 0;
	}
    }
    else
    {
    div = num / 3; // if num > 3
    for(i=0; i < 3 ;i++)
    {
	k = j + 1;
	thread[i].start = k;
	j = k + div;
	if ( j < num)
	{
	thread[i].end = j;
	}
	else if( k == num )
	{
	    if(i != 3)
	    {
	    thread[i].end = 0;
	    thread[i+1].start = 0;
	    thread[i+1].end = 0;
	    break;
	    }
	    else
	    {
		thread[i].end = 0;
		break;
	    }
	}
	else 
	{
	    if(i == 3)
	    {
		thread[i].end = num;
		break;
	    }
	    else
	    {
	    thread[i].end = num;
	    thread[i+1].start= 0;
	    thread[i+1].end = 0;
	    break;
	    }
	}
    }
    }
    
    for(i = 0; i < 3; i++) // create thread
    {
	pthread_create(arr[i],NULL,fact,&thread[i]);
    }
    for( i = 0; i<3 ; i++) // join thread
    {
	pthread_join(*arr[i],(void**)&result[i]);
    }
    int factorial = 1; 
    for(i = 0; i < 3; i++) // find last factorial
    {
	factorial *= result[i];
    }
    printf("Factorial of %d is %d\n",num,factorial);

    return 0;
}
