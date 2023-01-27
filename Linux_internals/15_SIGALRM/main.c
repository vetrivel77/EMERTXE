/*
NAME		: VETRIVEL P
DATE		:20/01/2023
DESCRIPTION	:Program to implement alarm with snooze for given time and date using SIGALRM
SAMPLE I/O	:
1. ./alarm (No arguments) 
Error: No arguments passed
Usage: ./alarm  [dd/mm/yy] 

2. ./alarm 30:15 

Error: Invalid time 

3. ./alarm 22:10 

set alarm for 10:10 PM for today 

4. ./alarm 22:10 02/03/16

set alarm for 10:10 PM for today 

5. When alarm occurs 

Wake­up...Alarm..!! 

1. Snooze     2. Exit 

if user select 

1 Enter snooze time :

2 

( After 2 mins above process will repeat until user gives exit)

   */
#define _XOPEN_SOURCE
#include<stdio.h>
#include<signal.h>
#include<locale.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int alarm_flag = 0;
void handler(int signum)  //handler function
{
    alarm_flag = 1;
    printf("Wake up ...Alarm..!!\n");
}
int main(int argc, char*argv[])
{
    if(argc <= 1)  // check required arguments passed or not
    {
	printf("Error: No arguments passed\nUsage: ./alarm [H:M:S] [dd-mm-yy]\n");
	return 1;
    }
    struct tm tm,*cur_tm;
    int sec,user_time;
    memset(&tm,0,sizeof(tm));  // clear structure
    memset(&cur_tm,0,sizeof(cur_tm));
    time_t cur_time = time(NULL); // read current time from epoch time
    cur_tm = localtime(&cur_time); // convert seconds to H:M:S dd-mm-yy formate
    if(argc == 2)   // if date not passed
    {
	strptime(argv[1],"%H:%M:%S",&tm);  //string formate date converted to time formate
	tm.tm_mday = cur_tm->tm_mday; // store today date to structure tm
	tm.tm_mon = cur_tm->tm_mon;
	tm.tm_year = cur_tm->tm_year;
    }
    else
    {
	strptime(argv[1],"%H:%M:%S",&tm);  // if date and time passed both strings changed to time and date formate
	strptime(argv[2],"%d-%m-%Y",&tm);

    }
    user_time = mktime(&tm); // convert to seconds
    if(user_time < cur_time)  // if user time less than current time ,error 
    {
	printf("Error: Inavlid time\n");
	return 1;
    }
    int alarm_time = user_time - cur_time; // find seconds 
    printf("Set alarm for %s for today\n",argv[1]);
    alarm(alarm_time);  // signal generate
    signal(SIGALRM,&handler); // signal register
    while(1)
    {
	if(alarm_flag) // after 1st alaram ,option for snooz or exit
	{
	    alarm_flag = 0;
	    printf("1. snooze\n2. exit\noption : ");
	    int opt;
	    scanf("%d",&opt);
	    switch(opt)
	    {
		case 1:
		 printf("Enter snooze time(in seconds) : ");
		 scanf("%d",&sec); // read snooze second
		 alarm(sec); // signal generate
		 signal(SIGALRM,&handler); // signal registre
		 break;
		case 2: // exit condition
		 exit(0);
	    }
	}
    }
    
    return 0;
}
