/*
name: vetrivel.p
date:11/06/2022
description: A7 - WAP to print triangle pattern as shown below
sample i/p and o/p:
Sample Output:
Test Case 1:
Enter the number: 4
1 2 3 4
5     6
7 8
9

Test Case 2:
Enter the number: 5
1 2 3 4 5
6       7
8    9
10 11
12
  
 */

#include<stdio.h>

int main()

{
    // variable declaration
    
    int row,col,num,res=1;

    // read value from the user
    
    printf("enter the number:");
    scanf("%d",&num);

   // using for loop get value one by one row and col
    
    for(row=1 ; row <= num ; row++)
    
    {

    for(col=1; col <= num ; col++)
       
        {                         
    // using if  to get the numbers based on valuve and empty space considering

           if(row == 1 || col == 1 || col == num-row+1)             
           
   // value printing in rows and columns         
                      
           {             
            
               printf("%d ",res++);
            
        }
  // to print the emety space 
       
        else if(col>num-row+1)
       
       {
           printf(" ");
       }
        
           else
        {
          printf("  ");  
               
           }
               }

       printf("\n");
        
              
            }   
         
return 0;

}



