/*
name: vetrivel.p
date: 05/07/2022
description: A30 - WAP to generate fibbonacci numbers using recursion
sample i/p and o/p:
Test Case 1 :
user@emertxe] ./fibbonacci_series
Enter a number: 8
0, 1, 1, 2, 3, 5, 8

Test Case 2:
Enter a number: 10
0, 1, 1, 2, 3, 5, 8

Test Case 3:
Enter a number: 21
0, 1, 1, 2, 3, 5, 8, 13, 21

Test Case 4:
Enter a number: -12
Invalid input
*/

#include <stdio.h>

void positive_fibonacci(int, int, int, int);                          // function anme and parameters

int main()
{
    int limit;                                                        // variable declaration
             
    printf("Enter the limit : ");                                     // read num from user
    scanf("%d", &limit);
    
    positive_fibonacci(limit, 0, 1, 0);
    
    return 0;
}


void positive_fibonacci(int limit, int n1, int n2, int next)         // function prototype
{
    if (limit < 0)                                                   // entered value negative value to print the error message                   
    {
        printf("Invalid input\n");
    }
    while( next <= limit)                                            // to generate the positive fibonacci series	    
    {
		printf("%d,",next);
		n1=n2;
		n2=next;
		next=n1+n2;	    
    }
}
