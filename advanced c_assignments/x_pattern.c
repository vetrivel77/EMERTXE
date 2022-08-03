/*
name: vetrivel.p
date: 09/06/2022
description : A6 - WAP to print the numbers in X format as shown below
sample i/p and o/p:
Test Case 1:
Enter the number: 4
1  4
 23
 23
1  4

Test Case 2:
Enter the number: 5
1   5
 2 4
  3
 2 4
1   5

 */

#include<stdio.h>

int main()
{

//variable declaration
    
    int row,col,num;

 // read number from the user
    
    printf("Enter the number:");

    scanf("%d",&num);

  // intialize row and col valuve using loops and compare to row and col valuves
    
        for(row = 1; row <= num; row++)
    { 
     
        for(col = 1; col <= num; col++)    
        {
   
   // based on user value to calculate the rows and col values    
        
        if(col == row || col == num - row + 1)
        
  // to print the rows and col integer values                  
        {   
            printf("%d",col);         

        }
                      
        else        
        {
          printf(" ");
        }
    }

    printf("\n");
    }

    return 0;
}
