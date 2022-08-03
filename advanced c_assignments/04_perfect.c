/*
name: vetrivel.p
date: 10/06/2022
description: A4 - WAP to check if number is perfect or not
sample i/p and o/p:

Test Case 1:

Enter a number: 6

Yes, entered number is perfect number

Test Case 2:
Enter a number: 10

No, entered number is not a perfect number

Test Case 3:
Enter a number: -1

Error : Invalid Input, Enter only positive number

*/

#include<stdio.h>

int main()

{
  //variables declaration
    
    int i,num,sum=0;

  //read number from the user
     printf("Enter a number: ");
     scanf("%d",&num);
     
  //to check enter number +ve to excute or -ve to print the error meassage   
     
     if(num < 0)
   {
         
      printf("Error : Invalid Input, Enter only positive number\n");
             }
     
     else     
     {     
         
  //using loop get one by one number from i to execute the value          
         
         for(i=1 ; num > i ; i++)
         
         {
                                   
          if(num % i == 0)
     {      
        sum = sum + i;
     }
       
         }          
    // comparing num sum value depends on number to  print the message
       
         if(num == sum ) 
          
         printf("Yes, entered number is perfect number\n");
          
      else
    
        printf("No, entered number is not a perfect number\n");
         
     }
            
           
   return 0;    
  
}
