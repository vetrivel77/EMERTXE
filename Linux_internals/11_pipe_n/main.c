/*
NAME: VETRIVEL P
DATE: 13/1/2023
DESCRIPTION	:  WAP to implement 'n' pipes to execute 'n+1' commands
SAMPLE I/O AND  O/P:
Pre-requisites:- 

Knowledge about system calls, How to read and understand ‘man pages’.
Good knowledge about processes and IPC. 
Working of pipe & dup system calls.
Objective: 
• To understand working of pipe between 'n+1' process. 

Requirements: 

Create two child process and execute commands passed from command-line arguments 
Each command is separated by a '|' (pipe) character. 
First child execute first command (with or without options) and pass o/p to next. 
Second child executes second command (after '|') will reads I/p from first cmd. 
Parent will wait for both child process to finish .
Sample execution: 

./pipe (No arguments)
   Error: No arguments passed,Provide atleast one pipe  or more

   Usage: ./pipe <command1> '|' <command2>

   Usage: ./pipe <command1> '|' <command2> '|' <command3> etc


2../pipe ls '|' wc

    5 25 4

3. ./pipe ls -­l '|' grep “pattern” '|' wc -­l 

    5 5 25   
*/

#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
   int i, p_pos = 0,count = 0,l=0;
   char *const arg[10];// arg1[10][10];
   const char* arg1[10];

   if(argc <= 1)  // check required number of command passed or not
   {
        printf("Error: No arguments passed Usage: ./pipe <command1> '|' <command2>\n");
        return 1;
   }
   for(i = 1; i < argc; i++)   // check "|" passed or not, if passed find position
   {
    
       if(strcmp(argv[i],"|") == 0 && p_pos==0)
       {	    
           p_pos = i;	
           count++;	
           break;    
       }
       else if(strcmp(argv[i],"|"))
       {
           count++;
       }
   }
   if(!p_pos)
   {
       printf("Error : Insufficient arguments passed Usage: ./pipe <command1> '|' <command2>\n");      
       return 1;
   }
   int p[2];  // declaration of array for pipe read and write operation
   pid_t pid = fork();  // child process creation
   if(pid > 0)  // parent
   {    
       wait(NULL);
	   for(i = p_pos+1; i < (count-1);i++) //loop for 'n' number of pipe
	   {	    
           pid_t pid2 = fork();  // create new child process
	    
           if(strcmp(argv[i],"|")==0) // find next pipe position	    
           {		
               p_pos = i;	    
           }	    
           int j = p_pos+1; // store position of next command
	    
           if(!pid2)   // new child process	    
           {	    
               if(i != count)  //  if not last pipe, write o/p of command to buffer	    
               {		
                   dup2(p[0],0);		
                   dup2(p[1],1);		
                   execlp(argv[j],argv[j],(char*)NULL);		
                   close(p[0]);		
                   close(p[1]);
	    
               }           
	           else   // if it is last pipe last command o/p print on stdout	    
               {		               
                   close(p[1]);		             
                   dup2(p[0],0);
		           execlp(argv[j],argv[j],(char*)NULL);		                                            
                   close(p[0]);	    
           
               }
	    
           }
           

       }
       
   }               
   else if(!pid)           
   {               
              
       int j = 0;               
       for(i = 1; i <= p_pos; i++)  // store commands till pipe to string array              
       {                           
                   
           strcpy(arg[j],argv[i]);	           
           j++;                   
       }               
       strcpy(arg[j],"(char*)NULL");               
       close(p[0]); //close read end of pipe              
       dup2(p[1],1);  // duplicate of write file create at file descriptor 1 , for that close stdout               
       execvp(argv[1],argv);  // execute 1st command and o/p will stored in pipe read writte buffer               
       close(p[1]); //close write end of pipe              
       close(1);  //close file                 
   }     
   return 0;
   
}

