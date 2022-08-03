/*
name: vetrivel.p
date: 05/07/2022
description: A31 - WAP to generate negative fibbonacci numbers using recursion
sample i/p and o/p:
Sample execution: -
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

Test Case 3:
Enter a number: 21
Invalid input

*/

#include <stdio.h>
 
void negative_fibonacci(int, int, int, int);                     // function and parameters

int main()
{
    int limit;                                                   // variable declaration
    
    printf("Enter the limit : ");                                // read limit from user
    scanf("%d", &limit);
    
    negative_fibonacci(limit, 0, 1, 0);                          
}

void negative_fibonacci(int num, int n1, int n2, int next)       // function prototype

{
    if(num > 0)                                                  // user entered +ve value to print the error messaage
    {
        printf("Invalid input\n");
    }
    
    while( next >= num && next <= (-num))	                     // to generate the negative fibonacci series
    {
         printf("%d, ",next);
	     n1=n2;
	     n2=next;
	     next=n1-n2;	 
    }
}
