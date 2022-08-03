/*
description: A3 - WAP to generate negative Fibonacci numbers
sample i/p and o/p:

Test Case 1 :

user@emertxe] ./fibbonacci_series

Enter a number: -8

0, 1, -1, 2, -3, 5, -8

Test Case 2:

Enter a number: -10

0, 1, -1, 2, -3, 5, -8

Test Case 3:

Enter a number: -21

0, 1, -1, 2, -3, 5, -8, 13, -21

Test Case 4: 

Enter a number: -13

0, 1, -1, 2, -3, 5, -8, 13

Test Case 4: 

Enter a number: 13

Invalid input

 */

#include<stdio.h>

int main()

{
    // declare the varaibles 
           int i,num;    
       
           int f1 = 0, f2 = 1;
      
    // read num from the user       
    
        printf("Enter a number: ");

        scanf("%d",&num);

    // using if else condition enter -ve  to print the error    
       
        if(num <= 0)
       {

        printf("%d, %d",f1,f2);    
           
          i= f1 - f2;            
       }  
       else
       {
        printf("invalid input\n");   
       
       }
       
    // using while loop one - one number subtraction and to creat new term   
       
       while(i >= num && i <= (-num))

               {
                   printf(", %d",i);
                   
                   f1 = f2;
                      f2 = i;
                      i = f1 - f2;
                 
               }
    return 0;

}
