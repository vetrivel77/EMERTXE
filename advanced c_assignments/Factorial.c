/*
name: vetrivel.p
date: 13/02/2022
description: A29 - WAP to find factorial of given number using recursion
sample i/p and o/p:
Test Case 1:
user@emertxe] ./factorial
Enter the value of N : 7
Factorial of the given number is 5040

Test Case 2:
Enter the value of N : 5
Factorial of the given number is 120

Test case 3:
Enter the value of N : -1
Invalid Input

Test case 4:
Enter the value of N : 0
Factorial of the given number is 1
*/

# include <stdio.h>
# include <stdlib.h>

int main()

{     
    // variable declaration
 
    static int num, fact = 0;
 
    int status;
    
    // Condition to read and validate the entered number
      
    if (fact == 0) 
    {
           
        printf("Enter the value of N : ");    
        status = scanf("%d", &num); 
        
    // Validation to check if entered number is a positive integer
    if (status != 1 || num < 0)         
    {
          
        printf("Invalid input\n");
              
        return 0;   
      
    }
         
    fact = 1;  
  
    }  
    
    // to calculate factorial recursion     
    if (num)       
    {
   
        fact *= num --;
   
        main();
   
        return fact;
  
     }
  
    //Display the result
  
     printf("Factorial  of the given number is %d\n", fact);
  
     fact = 0;

}
