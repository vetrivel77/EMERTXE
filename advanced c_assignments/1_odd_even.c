/*
name: vetrivel.p
date:8/06/2022
description: A1 - WAP to check if number is odd or evenVirtual programming lab
sample i/p:                      

Test Case 1:

user@emertxe] ./even_odd

Enter the value of 'n' : -2

Test Case 2:

Enter the value of 'n' : 2

Test Case 3:

Enter the value of 'n' : 0

sample o/p:

Test Case 1:

user@emertxe] ./even_odd

-2 is negative even number

Test Case 2:

2 is positive even number

Test Case 3:

0 is neither odd nor even
*/

#include<stdio.h>

int main()
{    
   //variable declaration    
   
      int num;
  // value read from the user
    
      printf("Enter the value of 'n' : ");
      scanf("%d",&num);
    
    // value 0 to print error message    
       
    if(num == 0)     
       {     
      printf("%d is neither odd or even\n",num);
       }
    // enter value is +ve to find and printing   
    
     else if(num > 0)                               
       {           
          if(num%2 == 0)
         {  
        printf(" %d is positive even number\n",num);
         }      
         else
           {
       printf("%d is positive odd number\n",num);             
         }       

       }
 
    // enter value is -ve to find and printing
    
    else if(num < 0)
{
    if(num%2 == 0)
    {
        printf(" %d is negative even number\n",num);        
    } 
    else    
    {
        printf(" %d is negative odd number\n",num);
    }
}   
    return 0;

        
    } 
